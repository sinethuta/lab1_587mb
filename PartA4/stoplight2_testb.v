`timescale 1 ns / 1ps
module stoplight2_testb;
	reg PED, CLK;
	stoplight2 x1(PED,CLK,G,Y,R);
	initial begin
		x1.S0 = 0;
		x1.S1 = 0;
		x1.S2 = 0;
		x1.S3 = 0;
		x1.S4 = 0;
		CLK = 0;
		PED = 0;
		$dumpfile("stoplight2_testb.vcd");
		$dumpvars(0,stoplight2_testb);
		#1500000 $finish; // this is to check when clock go over 1M 
	end

	always #30 CLK=~CLK; // increasing clock speed so the program reaches 1M faster

	always @(posedge CLK) begin
		if ($time <= 1000000) begin
			if ({x1.S4,x1.S3,x1.S2,x1.S1,x1.S0} == 4'b01000) begin
				$display("%8d", $time," state:",x1.S4,x1.S3,x1.S2,x1.S1,x1.S0, "  (reached target)"); 
				$display("The number of clock cycles until reachable: ","%8d", $time);
				$finish; 
			end
			else begin
				$display("%8d", $time, " state:", x1.S4,x1.S3,x1.S2,x1.S1,x1.S0);
			end
			PED = $random;
		end
		else begin
		$display("Timed out, unreachable for state 01000");
		$finish; 
		end
	end
endmodule

module stoplight2(Ped,clock,SigG,SigY,SigR);
input Ped,clock;
reg S4,S3,S2,S1,S0;
output SigG,SigY,SigR;
wire n15,n16,n17,n18,n19,n20,n21,n22,n23,n24,n25,n26,n27,n28,n29,n30,n31,n32,n33,n34,n35,n36,n37,n38,n39,n40,n41,n42,n43,n44,n45,n46,n47,n48,n49,n50,n51,n52,n53,n54,n55,n57,n58,n60,n61,n62,n63,n64,n65,n67,n68,n69,n70,n71,n72,n73,n74,n75,n77,n78,n79,n80,n81,n82,n83,n84,n85,n86,n88,n89,n90,n91,n92,n93,n94,n95,n96,n97,n99,n100,n101,n102,n103,n104,n105,n106,n107,n108,n109,n110,n111,n112,n113,n114,n116,n117,n118,n119,n120,NS4,NS3,NS2,NS1,NS0;
not g0(n15,S0);
not g1(n16,S4);
not g2(n17,S3);
and g3(n18,n17,n16);
and g4(n19,n18,S2);
and g5(n20,n19,n15);
not g6(n21,n20);
not g7(n22,S1);
not g8(n23,Ped);
and g9(n24,n23,n22);
and g10(n25,n24,n19);
not g11(n26,n25);
and g12(n27,Ped,S0);
and g13(n28,n27,n19);
not g14(n29,n28);
and g15(n30,n29,n26);
and g16(n31,n30,n21);
not g17(n32,S2);
and g18(n33,n18,n32);
and g19(n34,S0,S1);
and g20(n35,n34,Ped);
and g21(n36,n35,n33);
not g22(n37,n36);
and g23(n38,n32,n17);
and g24(n39,n34,n23);
and g25(n40,n39,n38);
not g26(n41,n40);
and g27(n42,n41,n37);
and g28(n43,S2,n17);
and g29(n44,n43,n39);
not g30(n45,n44);
and g31(n46,n32,S4);
and g32(n47,n15,n22);
and g33(n48,n47,n46);
not g34(n49,n48);
and g35(n50,n17,S4);
not g36(n51,n50);
and g37(n52,n51,n49);
and g38(n53,n52,n45);
and g39(n54,n53,n42);
and g40(n55,n54,n31);
not g41(SigG,n55);
and g42(n57,S3,n16);
and g43(n58,n22,n32);
and g44(SigY,n58,n57);
and g45(n60,S0,n22);
and g46(n61,n60,n33);
not g47(n62,n61);
and g48(n63,n33,n15);
not g49(n64,n63);
and g50(n65,n64,n62);
not g51(SigR,n65);
and g52(n67,Ped,n15);
and g53(n68,n67,n50);
not g54(n69,n68);
and g55(n70,S0,S4);
and g56(n71,n70,n23);
not g57(n72,n71);
and g58(n73,n72,n69);
and g59(n74,n73,n45);
and g60(n75,n74,n29);
not g61(NS4,n75);
and g62(n77,S1,S2);
and g63(n78,n77,n71);
not g64(n79,n78);
and g65(n80,n57,n15);
not g66(n81,n80);
and g67(n82,n15,S3);
and g68(n83,n82,Ped);
not g69(n84,n83);
and g70(n85,n84,n81);
and g71(n86,n85,n79);
not g72(NS3,n86);
and g73(n88,n22,S2);
and g74(n89,n23,S0);
and g75(n90,n89,n88);
not g76(n91,n90);
and g77(n92,n15,S2);
and g78(n93,n92,Ped);
not g79(n94,n93);
and g80(n95,n94,n91);
and g81(n96,n95,n21);
and g82(n97,n96,n42);
not g83(NS2,n97);
and g84(n99,n70,n24);
not g85(n100,n99);
and g86(n101,S2,n16);
and g87(n102,n101,n67);
not g88(n103,n102);
and g89(n104,n103,n100);
and g90(n105,n15,S1);
and g91(n106,n105,Ped);
not g92(n107,n106);
and g93(n108,S1,n16);
and g94(n109,n108,n15);
not g95(n110,n109);
and g96(n111,n110,n107);
and g97(n112,n111,n104);
and g98(n113,n62,n37);
and g99(n114,n113,n112);
not g100(NS1,n114);
and g101(n116,n81,n69);
and g102(n117,n110,n94);
and g103(n118,n117,n116);
and g104(n119,n64,n26);
and g105(n120,n119,n118);
not g106(NS0,n120);
always @(posedge clock) begin
S4<=NS4;
S3<=NS3;
S2<=NS2;
S1<=NS1;
S0<=NS0;
end
endmodule
//State:01000