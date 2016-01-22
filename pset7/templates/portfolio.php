<div>
    <table class = "table table-striped">
		<tr>
			<th>Symbol</th>
			<th>Name</th> 
			<th>Shares</th>
			<th>Price</th>
			<th>Total</th>
		</tr>

		<?php

		    foreach ($positions as $position)
		    {
		        print("<tr>");
		        print("<td>" . $position["symbol"] . "</td>");
				print("<td>" . $position["name"] . "</td>");
		        print("<td>" . $position["shares"] . "</td>");
		        print("<td>$" . number_format($position["price"], 2) . "</td>");
				print("<td>$" . number_format($position["shares"] * $position["price"], 2) . "</td>");
	
		        print("</tr>");
		    }

		?>

		<tr>
			<td colspan="4"> CASH</td>
			<td>$<?= number_format($cash, 2) ?></td>
		</tr>

	</table>
</div>
