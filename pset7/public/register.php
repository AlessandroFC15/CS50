<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }


    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
	
	// Validate the submission

        if (empty($_POST["username"]))
        {
            apologize("You must provide your username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
	else if ($_POST["password"] != $_POST["confirmation"])
	{
	    apologize("The password and the confirmation don't match.");
	} 

	// Insert a new user into your database
	query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.00)", $_POST["username"], crypt($_POST["password"]));

	if (query === false)
	{
	    apologize("Invalid username or password!");
	} else
	{
	    $rows = query("SELECT LAST_INSERT_ID() AS id");
	    $id = $rows[0]["id"];

	    // remember that user's now logged in by storing user's ID in sessions
	    $_SESSION["id"] = $id;

	    redirect("/");	

	}

    }

	

?>
