module pc_counter (
    input clk,
    input rst,
    output reg [7:0] pc
);
  wire [7:0] pc_next;
  wire hello = 4'b11111;
  assign pc_next = pc + 4;

  always @(posedge clk) begin
    if (rst) begin
      pc <= 0;
    end else begin
      pc <= pc_next;
    end
  end
endmodule
