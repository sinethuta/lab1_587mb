`timescale 1 ns / 1ps
module ex1_testb;
	reg CLK, a;
	ex1 x1(CLK, a, y);
	initial begin
		x1.S0 = 0;
		x1.S1 = 0;
		CLK = 0;
		a = 0;
		$dumpfile("ex1_testb.vcd");
		$dumpvars(0,ex1_testb);
		#1500000 $finish; // this is large enough to check when clock go over 1M 
	end

	always #30 CLK=~CLK; // increasing clock speed so the program reaches 1M faster

	always @(posedge CLK) begin
		if ($time <= 1000000) begin
			if ({x1.S1,x1.S0} == 2'b11) begin
				$display("%8d", $time," state:",x1.S1,x1.S0, "  (reached target)"); 
				$display("The number of clock cycles until reachable: ","%8d", $time);
				$finish; 
			end
			else begin
				$display("%8d", $time, " state:",x1.S1,x1.S0);
			end
			a = $random;
		end
		else begin
		$display("Timed out, unreachable for state: 11");
		$finish; 
		end
	end
endmodule


module ex1(clock,A,Y);
input clock;
input A;
output Y;
reg S0,S1;
wire X1,NS0,NS1;
and g0(X1,S0,S1);
and g1(NS1,A,X1);
not g2(NS0,X1);
and g3(Y,A,X1);
always @(posedge clock) begin
S1<=NS1;
S0<=NS0;
end
endmodule
//State:11