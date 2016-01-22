<?php

    // configuration
    require("../includes/config.php"); 

	$history = query("SELECT * FROM history WHERE id = ?", $_SESSION["id"]);

	render("history_table.php", ["title" => "C$50 | History", "history" => $history]);
?>
