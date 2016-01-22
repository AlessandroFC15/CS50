<div>
    <table class = "table table-striped">
		<tr>
			<th>Transaction</th>
			<th>Date/Time</th> 
			<th>Symbol</th>
			<th>Shares</th>
			<th>Price</th>
		</tr>

		<?php

		    foreach ($history as $operation)
		    {
		        print("<tr>");
		        print("<td>" . $operation["type"] . "</td>");
				print("<td>" . date("F, j, Y | g:ia", strtotime($operation["date"])) . "</td>");
		        print("<td>" . $operation["symbol"] . "</td>");
		        print("<td>" . $operation["shares"] . "</td>");
				print("<td>$" . number_format($operation["price"], 2) . "</td>");
		        print("</tr>");
		    }
		?>

	</table>
</div>

