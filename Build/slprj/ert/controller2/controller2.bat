call "setup_msvc.bat"

cd .

if "%1"=="" (nmake  -f controller2.mk all) else (nmake  -f controller2.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
