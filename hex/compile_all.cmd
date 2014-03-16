@echo off
forfiles /M *.psm /C "cmd /c pblazasm -3 -v -l@fname.lst -x@fname.hex @file"
pause
