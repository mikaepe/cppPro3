n = 10; m = 10; 
fID = fopen('outfile.bin');
A = fread(fID,[(n+1)*(m+1) 2],'double');
fclose(fID);
plot(A(:,1),A(:,2),'*');
