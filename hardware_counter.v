//
// hardware counter
//


module hardware_counter(
    input clk_ip,
    input rstn_ip,
    output [31:0] counter_op
);

    reg [31:0] cycles;

    always @(posedge clk_ip or negedge rstn_ip) begin
        if(!rstn_ip)begin
            cycles <= 32'd0;
        end else begin
            cycles <= cycles + 1;
        end
    end

    assign counter_op = cycles;

endmodule
