# implement-message-queue

this shows simple message q implementation

p1 sends few messages to p2 and p3
and displays the info of msqid_ds structure
-last send time
-last rcv time
-last send pid
-last rcv pid
-# of meassages in queue

p2 reads the messages of its type i.e. type 2
and also displays msqid_ds info

p3 reads the message of its type i.e. type 3
and also displays msqid_ds info
