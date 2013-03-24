playctl
================

companion program for multimovie player
send command to multiple multimovieplayer client over multicast
originally java program made in 2004 and it is compatible

this program currently controll 1 movie on id0 on each multimovieplayer client

:usage
program folder bin/
playctl.txt in folder  bin/data

plyctl read playctl.txt for command.
read one line and check 1st character.
'WAITM' wait command ommitting 5 characters and get number
WAITM5000  Wait for 5000millisec

"STARTM" go to start position of the movie

"FWPLAY" UNPAUSE and play forward

"A00200" stop at 200th frame of the movie
you can change frame number.
some quicktime movie doesnot support the frame( writes error )
motion jpeg is ok.

"INLOP10" loop back point use with "OUTLOP"
INLOP10 10 is the number of loop

"OUTLOP" loop to INLOP point


WAITM5000   wait 5secs
STARTM      start position and pause movie
FWPLAY      unpause and go forward
WAITM3000   wait 3sec
INLOP2      loop 2times
A00200      stop at 200th frame
WAITM2000   wait 2sec
FWPLAY      unpause and go forward      
WAITM5000   wait 5secs
OUTLOP      loopback to previous "INLOP" if count is met go down
