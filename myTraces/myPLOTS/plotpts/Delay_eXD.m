


fXY_ran=importdata("plotsXY_random.txt");
fXY_trans=importdata("plotsXY_transpose.txt");

fDyAd_ran=importdata("plotsDyAD_Random.txt");
fDyAd_trans=importdata("plotsDyAD_Transpose.txt");

fNOP_ran=importdata("plotsNOP_Random.txt");
fNOP_trans=importdata("plotsNOP_transpose.txt");

fOE_ran=importdata("plotsOE_random.txt");
fOE_trans=importdata("plotsOE_transpose.txt");


xyRAN_pir=fXY_ran(:,1);
xyRAN_delay=fXY_ran(:,2);
xyRAN_ed=fXY_ran(:,3);

xyTRANS_pir=fXY_trans(:,1);
xyTRANS_delay=fXY_trans(:,2);
xyTRANS_ed=fXY_trans(:,3);


DyAdRAN_pir=fDyAd_ran(:,1);
DyAdRAN_delay=fDyAd_ran(:,2);
DyAdRAN_ed=fDyAd_ran(:,3);

DyAdTRANS_pir=fDyAd_trans(:,1);
DyAdTRANS_delay=fDyAd_trans(:,2);
DyAdTRANS_ed=fDyAd_trans(:,3);


oeRAN_pir=fOE_ran(:,1);
oeRAN_delay=fOE_ran(:,2);
oeRAN_ed=fOE_ran(:,3);

oeTRANS_pir=fOE_trans(:,1);
oeTRANS_delay=fOE_trans(:,2);
oeTRANS_ed=fOE_trans(:,3);


nopRAN_pir=fNOP_ran(:,1);
nopRAN_delay=fNOP_ran(:,2);
nopRAN_ed=fNOP_ran(:,3);

nopTRANS_pir=fNOP_trans(:,1);
nopTRANS_delay=fNOP_trans(:,2);
nopTRANS_ed=fNOP_trans(:,3);

plot(xyTRANS_pir,xyTRANS_ed);
hold;
plot(DyAdTRANS_pir,DyAdTRANS_ed,'r');
plot(oeTRANS_pir,oeTRANS_ed,'c');
plot(nopTRANS_pir,nopTRANS_ed,'g');

%plot(xyTRANS_pir,xyTRANS_delay);
%hold;
%plot(DyAdTRANS_pir,DyAdTRANS_delay,'r');
%plot(oeTRANS_pir,oeTRANS_delay,'c');
%plot(nopTRANS_pir,nopTRANS_delay,'g');

%plot(xyRAN_pir,xyRAN_ed);
%hold;
%plot(DyAdRAN_pir,DyAdRAN_ed,'r');
%plot(oeRAN_pir,oeRAN_ed,'c');
%plot(nopRAN_pir,nopRAN_ed,'g');



legend({'XY','DyAD','OE','NOP-OE'},'location','southeast');
legend show;
xlabel('pir(packet/cycle/node)');
ylabel('Energy(J)');

