from uvm.seq import UVMSequence
from uvm.macros.uvm_object_defines import uvm_object_utils
from uvm.macros.uvm_message_defines import uvm_info, uvm_fatal
from uvm.macros.uvm_sequence_defines import uvm_do_with, uvm_do
from uvm.base import sv, UVM_HIGH, UVM_LOW
from wrapper_env.wrapper_item import wrapper_bus_item
from uvm.base.uvm_config_db import UVMConfigDb
from cocotb_coverage.coverage import coverage_db
import os
import random

class uart_tx_seq(UVMSequence):

    def __init__(self, name="uart_tx_seq"):
        UVMSequence.__init__(self, name)
        self.set_automatic_phase_objection(1)
        self.req = wrapper_bus_item()
        self.rsp = wrapper_bus_item()
        self.tag = name

    async def body(self):
        await uvm_do_with(self, self.req, lambda addr: addr == 0x8, lambda kind: kind == wrapper_bus_item.WRITE, lambda data: data == 3)
        await uvm_do_with(self, self.req, lambda addr: addr == 12, lambda kind: kind == wrapper_bus_item.WRITE, lambda data: data == 1)
        for _ in range(10):
            random_send = random.randint(1, 16)
            for __ in range(random_send):
                await uvm_do_with(self, self.req, lambda addr: addr == 0x4, lambda kind: kind == wrapper_bus_item.WRITE, lambda data: data in range(0, 0x80))
            for __ in range(random.randint(0, random_send)):
                await self.monitor.tx_received.wait()
                self.monitor.tx_received.clear()


uvm_object_utils(uart_tx_seq)
