playctl
================

companion program for multimovie player<br>
used openframeworks and used ofxNetwork<br>
<br>
send command to multiple multimovieplayer client over multicast<br>
originally java program made in 2004 and it is compatible<br>
use thread<br>
<br>
this program currently controll 1 movie on id0 on each multimovieplayer client<br>
<br>
:usage<br>
program folder bin/<br>
playctl.txt in folder  bin/data<br>
<br>
plyctl read playctl.txt for command.<br>
read one line and check 1st character.<br>
'WAITM' wait command ommitting 5 characters and get number<br>
WAITM5000  Wait for 5000millisec<br>
<br>
"STARTM" go to start position of the movie<br>
<br>
"FWPLAY" UNPAUSE and play forward<br>
<br>
"A00200" stop at 200th frame of the movie<br>
you can change frame number.<br>
some quicktime movie doesnot support the frame( writes error )<br>
motion jpeg is ok.<br>
<br>
"INLOP10" loop back point use with "OUTLOP"<br>
INLOP10 10 is the number of loop<br>
<br>
"OUTLOP" loop to INLOP point<br>
<br>
example<br>
<br>
WAITM5000   wait 5secs<br>
STARTM      start position and pause movie<br>
FWPLAY      unpause and go forward<br>
WAITM3000   wait 3sec<br>
INLOP2      loop 2times<br>
A00200      stop at 200th frame<br>
WAITM2000   wait 2sec<br>
FWPLAY      unpause and go forward<br>
WAITM5000   wait 5secs<br>
OUTLOP      loopback to previous "INLOP" if count is met go down<br>
