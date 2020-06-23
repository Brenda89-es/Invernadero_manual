#! /usr/bin/gnuplot

set multiplot layout 2,3
set grid

unset key 
set time top

# Gráfico 1: Control de la humedad en el suelo
set title "HUMEDAD SUELO EN CADA MEDIDA"
set xlabel "MEDIDA"
set ylabel "H.Suelo  [%]"
set xrange [0:100]
set yrange [0:100]
plot "invernadero_DATOS.lis" using 1:2 with impulses lw 4 lt rgb 'brown'

# Gráfico2: Control de la temperatura
set title "TEMPERATURA EN CADA MEDIDA"
set xlabel "MEDIDA"
set ylabel "Temperatura [ºC]"
set xrange [0:100]
set yrange [0:100]
plot "invernadero_DATOS.lis" using 1:2 with impulses lw 4 lt rgb 'red' 

# Gráfico 3: Control de la humedad ambiente
set title "HUMEDAD AMBIENTE EN CADA MEDIDA"
set xlabel "MEDIDA"
set ylabel "H.Ambiental [%]"
set xrange [0:100]
set yrange [0:100]
plot "invernadero_DATOS.lis" using 1:4 with impulses lw 4 lt rgb 'green'
 
# Gráfico 4: Control de la luminosidad
set title "LUMINOSIDAD EN CADA MEDIDA"
set xlabel "MEDIDA"
set ylabel "L [%]"
set xrange [0:100]
set yrange [0:100]
plot "invernadero_DATOS.lis" using 1:5 with impulses lw 4 lt rgb 'purple'

# Gráfico 5: Control del nivel del agua

set title "NIVEL AGUA EN CADA MEDIDA"
set xlabel "MEDIDA"
set ylabel "AGUA [%]"
set xrange [0:100]
set yrange [0:100]
plot "invernadero_DATOS.lis" using 1:6 with impulses lw 4 lt rgb 'blue'

unset multiplot

# PAUSA DE 8 SEGUNDOS PARA ACUMULAR DATOS
pause 3

# RELEEMOS EL ARCHIVO DE DATOS
reread

    
