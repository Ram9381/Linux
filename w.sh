#!/bin/bash
awk '{
	c+=length;	
	w+=NF;
	l++;
}
END {
  print "no of characters:" c;
  print "no of words:" w;
  print "no of lines:" l;
}' abc.txt

