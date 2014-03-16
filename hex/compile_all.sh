#!/bin/sh
for f in *.psm
do
	pblazasm -3 -v -l${f%.*}.lst -x${f%.*}.hex $f
done
