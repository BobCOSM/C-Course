#!/bin/bash
out_dir="out"
if [ ! -d $out_dir ]; then
	mkdir $out_dir
fi

make


