	<html>
	<head>
	<title>Interfata Casa</title>
	<meta http-equiv="refresh" content="1"><!--...-->
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
		
		$hol = "<td>" . "<h3>Hol</h3> " . "Temp:" . $holTemp . " Lum:" . $holLum . " Umid:" . $holUmi.  "</td>";
		
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
	    $valoriFisier = array(18);
		@$file_handle = FALSE ;
		@$file_handle2 = fopen("Debug.txt", "w+") or die("Could not openn") ;
		
		while($file_handle == FALSE )
		{
			@$file_handle = fopen("E:\Proiect Domotica\Proiect-Domotica\Proiect\Pc\SerialPortComunication\Input", "r");
		}	
		while (!feof($file_handle)) {
			$line = fgets($file_handle);
			fputs($file_handle2, $line);
			//echo $line;
			//echo strlen($line);

			if(strcmp(chop($line), 'C1') == 0)
			{
				$valoriFisier[1] = fgets($file_handle);
				$valoriFisier[2] = fgets($file_handle);
				$valoriFisier[3] = fgets($file_handle);
			}
			
			if(strcmp(chop($line), 'C2') == 0)
			{
				$valoriFisier[4] = fgets($file_handle);
				$valoriFisier[5] = fgets($file_handle);
				$valoriFisier[6] = fgets($file_handle);
			}
			
			if(strcmp(chop($line), "Hol") == 0)
			{
				$valoriFisier[7]= fgets($file_handle);
				$valoriFisier[8] = fgets($file_handle);
				$valoriFisier[9] = fgets($file_handle);
			}
			
			if(strcmp(chop($line), "Living") == 0)
			{
				$valoriFisier[10]= fgets($file_handle);
				$valoriFisier[11] = fgets($file_handle);
				$valoriFisier[12] = fgets($file_handle);
			}
			if(strcmp(chop($line), "Baie") == 0)
			{
				$valoriFisier[13]= fgets($file_handle);
				$valoriFisier[14] = fgets($file_handle);
				$valoriFisier[15] = fgets($file_handle);
			}
			
			if(strcmp(chop($line), "Bucatarie") == 0)
			{
				$valoriFisier[16]= fgets($file_handle);
				$valoriFisier[17] = fgets($file_handle);
				$valoriFisier[18] = fgets($file_handle);
			}
		}
		fclose($file_handle);
		
		echo CreateHouse(
		intval($valoriFisier[1]) ,intval($valoriFisier[2]) ,intval($valoriFisier[3]),
		intval($valoriFisier[4]) ,intval($valoriFisier[5]) ,intval($valoriFisier[6]),
		intval($valoriFisier[7]) ,intval($valoriFisier[8]) ,intval($valoriFisier[9]),
		intval($valoriFisier[10]) ,intval($valoriFisier[11]) ,intval($valoriFisier[12]),
		intval($valoriFisier[13]) ,intval($valoriFisier[14]) ,intval($valoriFisier[15]),
		intval($valoriFisier[16]) ,intval($valoriFisier[17]) ,intval($valoriFisier[18])
		); 
		
	?> 
	

	</body>
	</html