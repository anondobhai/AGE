@ECHO OFF
REM Build Everything

ECHO "Building everything..."

PUSHD engine
CALL build.bat
POPD 
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

PUSHD testbed
CALL build.bat
POPD
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVELS% && exit)

ECHO "All assemblies built succesfully."