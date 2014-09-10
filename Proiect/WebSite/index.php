	<html>
	<head>
	<title>Interfata Casa</title>
	<meta http-equiv="refresh" content="2"><!--...-->
	<style>
	table,th,td
		{
		border:1px solid black;
		border-collapse:collapse;
		}
	th, td
		{
		padding:15px;
		}
	
	<?php
	function CreateChambers(
	$tempValue, $tempCooler, $gasValue,
	$gasCooler, $gasLed
	){
		$tableInit = "	<table border=\"1\" style=\"width:300px\"> \n <tr> ";
		$tableEnd  = "		</tr>\n	</table>";
		$fanActivePath = "<img src=\"Fan.gif\" \">";
		$fanStopPath = "<img src=\"StoppedFan.png\" \">";
		$redLedOn = "<img src=\"RedLedOn.png\" height=\"42\" width=\"42\" \">";
		$redLedOff = "<img src=\"RedLedOff.png\" height=\"42\" width=\"42\" \">";
		$greenLedOn = "<img src=\"GreenLedOn.png\" height=\"42\" width=\"42\" \">";
		$greenLedOff = "<img src=\"GreenLedOff.png\" height=\"42\" width=\"42\" \">";
		//GasChamber creation
		$gasChamber = "<td>" .
		"<h3>Gaz</h3> " . 
		" Valoare Gaz: " . $gasValue;
		if ($gasCooler)  
		{
			$gasChamber = $gasChamber . $fanActivePath . "</td>";
		}
		else
		{
			$gasChamber = $gasChamber . $fanStopPath . "</td>";
		}
				
		$gasAllert = "<td>" . "<h3>Alerta Gaz</h3> " ;
		if ($gasLed)
		{
			$gasAllert = $gasAllert . $redLedOn . $greenLedOff;
		}
		else{
			$gasAllert = $gasAllert . $redLedOff . $greenLedOn;
		}
		
		//Temp chamber creation
		$tempChamber = "<td>" . "<h3>Temperatura</h3> " . "Valoare Temperatura:" . $tempValue;
		if($tempCooler)
		{
			$tempChamber = $tempChamber . $fanActivePath . "</td>";
		}
		else
		{
			$tempChamber = $tempChamber . $fanStopPath . "</td>";
		}
		"</td>";

		$tempAllert = "<td>" . "<h3>Alerta Temperatura</h3> " ;
		if ($tempCooler)
		{
			$tempAllert = $tempAllert . $redLedOn . "<br>" . $greenLedOff;
		}
		else{
			$tempAllert = $tempAllert . $redLedOff . "<br>" . $greenLedOn;
		}
		
		$gasTable = $tableInit . $gasChamber . $gasAllert . $tableEnd;
		$tempTable = $tableInit . $tempChamber . $tempAllert . $tableEnd;
		
		return $gasTable . $tempTable;
		}	
		//Scrierea titlului
		echo '</style> <H1 align = "center">Status</H1>';

	    $valoriFisier = array(5);
		@$file_handle = FALSE ;
		//Aici se citeste din fisier
		while($file_handle == FALSE )
		{
			@$file_handle = fopen("E:\Proiect Domotica\Proiect-Domotica\Proiect\Pc\SerialPortComunication\Input", "r");
		}	
		while (!feof($file_handle)) {
			$valoriFisier[1] = fgets($file_handle);
			$valoriFisier[2] = fgets($file_handle);
			$valoriFisier[3] = fgets($file_handle);
			$valoriFisier[4] = fgets($file_handle);
			$valoriFisier[5] = fgets($file_handle);
		}
		fclose($file_handle);
		//Apelarea functiei ce generează pagina html
		echo CreateChambers(
		intval($valoriFisier[1]) ,intval($valoriFisier[2]) ,intval($valoriFisier[3]),
		intval($valoriFisier[4]) ,intval($valoriFisier[5])); 
		
	?> 
	

	</body>
	</html