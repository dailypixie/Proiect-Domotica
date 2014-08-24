	<html>
	<head>
	<title>Interfata Casa</title>
	<!--<meta http-equiv="refresh" content="3">...-->
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
	function CreateHouse(
	$c1Temp, $c1Lum, $c1Umi,
	$c2Temp, $c2Lum, $c2Umi,
	$holTemp, $holLum, $holUmi,
	$livingTemp, $livingLum, $livingUmi,
	$baieTemp, $baieLum, $baieUmi,
	$bucatarieTemp, $bucatarieLum, $bucatarieUmi
	){
		$tableInit = "	<table border=\"1\" style=\"width:300px\"> \n <tr> ";
		$tableEnd  = "		</tr>\n	</table>";
		$c2 = "<td>" . "<h3>C2</h3> " . "Temp:" . $c2Temp . " Lum:" . $c2Lum . " Umid:" . $c2Umi.  "</td>";
		$c1 = "<td>" . "<h3>C1</h3> " . "Temp:" . $c1Temp . " Lum:" . $c1Lum . " Umid:" . $c1Umi.  "</td>";
		$bucatarie = "<td>" . "<h3>Bucatarie</h3> " . "Temp:" . $bucatarieTemp . " Lum:" . $bucatarieLum . " Umid:" . $bucatarieUmi.  "</td>";		
		
		$firstTable = $tableInit . $c1 . $c2 . $bucatarie . $tableEnd;
		
		$hol = "<td>" . "<h3>C1</h3> " . "Temp:" . $holTemp . " Lum:" . $holLum . " Umid:" . $holUmi.  "</td>";
		
		$holTable = $tableInit . $hol . $tableEnd;
		
		$living = "<td width=\"75%\">" . "<h3>Living</h3> " . "Temp:" . $livingTemp . " Lum:" . $livingLum . " Umid:" . $livingUmi.  "</td>";
		$baie = "<td>" . "<h3>Baie</h3> " . "Temp:" . $baieTemp . " Lum:" . $baieLum . " Umid:" . $baieUmi.  "</td>";
		
		$secondTable = $tableInit . $living . $baie . $tableEnd;
		
		
		$finalTable = $firstTable . $holTable . $secondTable;
		
	return $finalTable;}
	#function StartCommApp()
	#{
	#	$command = 'E:\Proiect Domotica\Proiect-Domotica\Proiect\Pc\Release\SerialPortComunication.exe';
	#	passthru($command);
	#}
		echo '</style> <H1 align = "center">Status</H1>';
		#StartCommApp();
		echo CreateHouse(
		21,22,23,
		31,32,33,
		41,42,43,
		51,52,53,
		61,62,63,
		71,72,73
		); 

	?> 

	</body>
	</html