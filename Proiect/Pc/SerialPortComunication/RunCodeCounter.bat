c:
cd "C:\Program Files (x86)\CCCC"
SET path="E:\Proiect Domotica\Proiect-Domotica\Proiect\Pc\SerialPortComunication\
SET output=--outdir=%1%
SET output=%output%/%2%
md %output%
cccc.exe %path%Conex.cpp" %path%Conex.h" %path%main.cpp" %path%Serial.cpp" %path%Serial.h" %output%
e:
cd "E:\Proiect Domotica\Proiect-Domotica\Proiect\Pc\SerialPortComunication"