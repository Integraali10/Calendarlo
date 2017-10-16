@echo off
set /P vers= < version.txt
git add .
git commit -m "New build project version %vers%"
git tag %vers%
git push -u origin master
pause