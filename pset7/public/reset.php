<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("change_password_form.php", ["title" => "C$50 | Change Password"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
		// Validate the submission
		if (empty($_POST["new_password"]) || empty($_POST["confirmation"]))
        {
            apologize("You must fill in all fields.");
        }
		else if ($_POST["new_password"] != $_POST["confirmation"])
		{
			apologize("The password and the confirmation don't match.");
		}

		query("UPDATE users SET hash = ? WHERE id = ?", crypt($_POST["new_password"]), $_SESSION["id"]);

		render("change_password_successful.php", ["title" => "C$50 | Change Password"]);

		
		
	
	}

?>
