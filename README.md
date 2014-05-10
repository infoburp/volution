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
opencl evolved images, features that'd be nice:

Features:
-any features at all
-screensaver mode
-(gif to multiple evolved images)

Algorithmstuff:
-split bigger images in smaller (e.g. 100x100px) subimages and evolve them in forked processes/threads.
(Is this the right way to do this? Why not try lots of times in parallel with random differences? This would avoid gaps between subimages)
-refine color palette (but allow deviations with some kind of acceptance)

Implementation:
-C++
-UI maybe in C# or with QT
-platform agnostic would be nice


int drawshape()
{
	//user draws shape from ui

    //start drawing shape vertex by vertex
    //until max number of vertices reached or user closes polygon by clicking on initial vertex

    //check if drawn shape gives a better fitness

    //if it does update the leaderDNA
}

int dragvertex()
{
	//user drags vertex from ui

    //user stops dragging vertex

    //check if dragged vertex improves fitness

    //if it does update the leaderDNA
}
0) Setup a random DNA string  (application start)

spawn a number of threads according to available resources

for each thread {
1) Copy the current DNA sequence and mutate it slightly
2) Use the new DNA to render polygons onto a canvas
3) Compare the canvas to the source image
4) If the new painting looks more like the source image than the previous painting did, then overwrite the current DNA with the new DNA
5) repeat from 1
}

functions:

-compute fitness (DNA, original image)
-render DNA to image
-mutate DNA(DNA,mutation type)
