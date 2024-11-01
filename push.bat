@echo off
:pull
git pull -v
if %ERRORLEVEL% neq 0 (
	goto pull

)
ping 127.0.0.1 /n 3 >nul
cls
echo ===================
echo ÉÏÒ»´Îtag: & powershell cat ./version.txt
echo ===================
set /p name="tag name:"
echo %name% > .\version.txt
set /p commit="commit:"
git add . -v
git commit -v -m "%commit%"
:push
git push -v
if %ERRORLEVEL% neq 0 (
	goto push
)


git tag -a "%name%" -m "%commit%"
:tag
git push --tags -v
if %ERRORLEVEL% neq 0 (
	goto tag
)
