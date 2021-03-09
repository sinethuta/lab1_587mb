module stoplight(Ped,clock,SigG,SigY,SigR);
input Ped,clock;
output SigG,SigY,SigR;
reg S3,S2,S1,S0;
wire n13,n14,n15,n16,n17,n18,n19,n20,n21,n22,n23,n24,n25,n26,n27,n28,n29,n30,n31,n32,n33,n34,n35,n36,n38,n39,n40,n42,n41,n43,n44,n45,n47,n48,n49,n50,n52,n53,n54,n55,n56,n57,n58,n59,n60,n61,n62,n64,n65,n66,n67,NS0,NS1,NS2,NS3;
not g0(n13,S3);
and g1(n14,S2,n13);
and g2(n15,Ped,S0);
and g3(n16,n15,n14);
not g4(n17,n16);
and g5(n18,S0,S1);
and g6(n19,n18,n14);
not g7(n20,n19);
and g8(n21,n20,n17);
not g9(n22,S0);
and g10(n23,n14,n22);
not g11(n24,n23);
not g12(n25,S2);
and g13(n26,n25,n13);
and g14(n27,n26,n18);
not g15(n28,n27);
not g16(n29,S1);
not g17(n30,Ped);
and g18(n31,n30,n29);
and g19(n32,n31,n14);
not g20(n33,n32);
and g21(n34,n33,n28);
and g22(n35,n34,n24);
and g23(n36,n35,n21);
not g24(SigG,n36);
and g25(n38,n25,S3);
and g26(SigY,n38,n29);
and g27(n40,S0,n29);
and g28(n41,n40,n26);
not g29(n42,n41);
and g30(n43,n26,n22);
not g31(n44,n43);
and g32(n45,n44,n42);
not g33(SigR,n45);
and g34(n47,n22,S3);
not g35(n48,n47);
and g36(n49,n48,n21);
not g37(NS3,n49);
not g38(NS2,n35);
and g39(n52,n22,S1);
not g40(n53,n52);
and g41(n54,n53,n42);
and g42(n55,S1,n25);
and g43(n56,n55,Ped);
not g44(n57,n56);
and g45(n58,n22,S2);
and g46(n59,n58,Ped);
not g47(n60,n59);
and g48(n61,n60,n57);
and g49(n62,n61,n54);
not g50(NS1,n62);
and g51(n64,n53,n48);
and g52(n65,n64,n33);
and g53(n66,n60,n44);
and g54(n67,n66,n65);
not g55(NS0,n67);
always @(posedge clock) begin
S3<=NS3;
S2<=NS2;
S1<=NS1;
S0<=NS0;
end
endmodule
//State:0100