volution
========

opencl image evolver

volution inputfile outputfile -a 90 -p 50 -v 6
 
-a - accuracy in % - how close a match until processing ends? (default 90%)
-p - polygons - max number of polygons in output image (default 50)
-v - vertices - max number of vertices per polygon (default 6)

Thread about what this is:

http://archive.rebeccablacktech.com/g/thread/S41780018

Javascript version:

http://alteredqualia.com/visualization/evolve/

C version for GNU/linux: http://github.com/infoburp/mona/

Windows version: http://rogeralsing.com/2008/12/11/genetic-programming-mona-lisa-source-code-and-binaries/

In progress opencl versions: github.com/infoburp/volution/ github.com/iscanti/iscanti

Wait, What?

This is a program that evolves a close match to an input image, made out of a set number of coloured polygons.

Some ideas from the thread:

Make it run on GPU! Make it run on clusters over a network (boinc or similar) Solve the local maximum problem Tweak the DNA mutation More parameters!
