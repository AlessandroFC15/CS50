<?php

    // configuration
    require("../includes/config.php");

    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("buy_form.php", ["title" => "C$50 | Buy"]);
    }
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    { 
		// validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must specify a stock to buy.");
        }
        else if (empty($_POST["shares"]))
        {
            apologize("You must specify a number of shares.");
        }
		else if ($_POST["shares"] <= 0)
		{
			apologize("Invalid number of shares.");
		}

		// Check if symbol exists

		$stock = lookup($_POST["symbol"]);

		if ($stock !== false)
		{
			// Check how much the buying is
			$price = $_POST["shares"] * $stock["price"];	

			// Check to see if the user can afford to buy it
			$cash = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);

			$cash = $cash[0]["cash"];

			if ($price <= $cash)
			{
				// Update the cash balance
				query("UPDATE users SET cash = cash - ? WHERE id = ?", $price, $_SESSION["id"]);

				// Add stock to the stock table
				query("INSERT INTO stock (id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + ?", $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["shares"], $_POST["shares"]);

				// Add operation to the history table
				query("INSERT INTO history (id, type, symbol, shares, price) VALUES(?, \"BUY\", ?, ?, ?)", $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["shares"], $stock["price"]);
				
				redirect("index.php");
			} else
			{
				apologize("You can't afford that.");
			}

		} 
		else 
		{
			apologize("Symbol not found!");
		}
	
    }

?>
