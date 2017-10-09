@echo off
title Script build Program
qmake -o Makefile main_widget_calendar.pro
echo program build 	press "Enter" for create exe file.
pause 
make
echo exe file create on path /relese.
pause 