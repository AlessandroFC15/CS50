<?php

    // configuration
    require("../includes/config.php");

    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
	    $stocks = query("SELECT * FROM stock WHERE id = ?", $_SESSION["id"]);

        render("sell_form.php", ["title" => "Sell", "stocks" => $stocks]);
    }
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    { 
		// Validate submission
		if ($_POST["symbol"] == "empty")
		{
			apologize("You must select a stock to sell.");
		} else if (empty($_POST["num_shares"]))
		{
			apologize("You must specify a number of shares to sell.");
		}
		else
		{
			// Calcular quanto deve ser creditado a conta
			
			// 1st Step = Ver quantas shares o usuário tem daquela empresa
			$shares = query("SELECT shares FROM stock WHERE id = ? and symbol = ?", $_SESSION["id"], $_POST["symbol"]);

			$shares = $shares[0]["shares"];

			// If the user wants to sell more than he has.
			if ($_POST["num_shares"] > $shares)
			{
				apologize("You don't have that many stocks of this company.");
			}

			// 2nd Step = Find out the price
			$info_symbol = lookup($_POST["symbol"]);

			if ($info_symbol !== false)
			{
				$price = $info_symbol["price"];
	
			} else
			{
				apologize("Symbol not found!");
			}		

			$value = $_POST["num_shares"] * $price;

			// Once we have the value, we have to update the shares from the table.
			
			// If the user wants to sell all of his stocks, then we will delete the row
			if ($_POST["num_shares"] == $shares)
			{
				query("DELETE FROM stock WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
			} else
			{
				query("UPDATE stock SET shares = shares - ? WHERE id = ? AND symbol = ?", $_POST["num_shares"], $_SESSION["id"], $_POST["symbol"]);
			}

			// Now, we have to update the cash balance
			query("UPDATE users SET cash = cash + ? WHERE id = ?", $value, $_SESSION["id"]);	
			
			// Add operation to the history table
			query("INSERT INTO history (id, type, symbol, shares, price) VALUES(?, \"SELL\", ?, ?, ?)", $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["num_shares"], $price);

            redirect("index.php");
		}	
    }

?>
