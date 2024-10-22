RISCV_GCC = riscv64-linux-gnu-gcc
RISCV_GCC_OPTS = -O3 -static
RISCV_LINK_OPTS ?= -L/usr/riscv64-linux-gnu/lib
RISCV_OBJDUMP ?= riscv64-linux-gnu-objdump --disassemble-all --disassemble-zeroes --section=.text

benchmarks = sum-array-if spmv mm median spmvif saxpy-if saxpy loopx2_ifx1 perm

benchmarks_riscv_bin  = $(addsuffix .riscv,  $(benchmarks))
benchmarks_riscv_dump = $(addsuffix .riscv.dump, $(benchmarks))

src_dir = .

define compile_template
$(1).riscv: $(wildcard $(src_dir)/srcs/$(1)/*)
	$$(RISCV_GCC) $$(incs) $$(RISCV_GCC_OPTS) -o $$@ $(wildcard $(src_dir)/srcs/$(1)/*.c) $(wildcard $(src_dir)/srcs/$(1)/*.S) $$(RISCV_LINK_OPTS)
	$$(RISCV_OBJDUMP) $$@ > $$@.dump
endef

$(foreach bmark,$(benchmarks),$(eval $(call compile_template,$(bmark))))

junk += $(benchmarks_riscv_bin) $(benchmarks_riscv_dump)

clean:
	rm -rf $(junk)