clang src\concat-multi-thread.cpp -o build/concat-multi-thread.exe -std=c++20 || goto :error

.\build\concat-multi-thread.exe
:: Debug runs of interpreter
.\build\concat-multi-thread.exe option1 option2
.\build\concat-multi-thread.exe cmt\first.cmt
:: END of debug
goto :EOF

:error
echo "Failed compilation!"
exit /b %errorLevel%
