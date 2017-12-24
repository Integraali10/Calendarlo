@echo off
color 0a
title Script build Program
set /P vers= < version.txt
ECHO %vers%
set /a vers+=1
ECHO %vers%
copy nul version.txt
ECHO %vers% >>version.txt
qmake -o Makefile main_widget_calendar.pro
copy version.txt debug/version.txt
copy version.txt release/version.txt
echo program build 	press "Enter" for create exe file.
MinGW32-make 
minGw32-make release
echo exe file create on path /debug und /release
cd C:\Users\Savva\Documents\GitProjects\Calendarlo\main_widget_calendar
compil32 /cc script1.iss
gitScript.bat
echo New version push on git
pause 
