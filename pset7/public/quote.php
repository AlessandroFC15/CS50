<?php

    // configuration
    require("../includes/config.php");

    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Get Quote"]);
    }
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    { 
	$stock = lookup($_POST["symbol"]);

	if ($stock === false)
	{
	    apologize("Symbol is not found!");
	} 
	else
	{
	    render("quote_display.php", ["title" => "Quote", "stock" => $stock]);
	}

	
    }

?>
