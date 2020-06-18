set terminal pngcairo size 1280,720
set output 'QuickSelect'
set title 'QuickSelect';
set xlabel "Input Size (N)"
set ylabel "Time Taken (Seconds)"

plot "fixed.txt" with linespoint linestyle 1 linetype 1, x*0.0000000300 with linespoint linestyle 6 linetype 4, x*0.000000012 with linespoint linestyle 6 linetype 2;
