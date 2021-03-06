#ifndef _PHIDIAS_ARCH_X86_ASM_VMX_REGS_H_
#define _PHIDIAS_ARCH_X86_ASM_VMX_REGS_H_

#define	VMXREG_16C_VPID		0x0000
#define	VMXREG_16C_POSTEDINT	0x0002
#define	VMXREG_16C_EPTP_INDEX	0x0004

#define	VMXREG_16G_ES_SEL	0x0800
#define	VMXREG_16G_CS_SEL	0x0802
#define	VMXREG_16G_SS_SEL	0x0804
#define	VMXREG_16G_DS_SEL	0x0806
#define	VMXREG_16G_FS_SEL	0x0808
#define	VMXREG_16G_GS_SEL	0x080a
#define	VMXREG_16G_LDTR_SEL	0x080c
#define	VMXREG_16G_TR_SEL	0x080e
#define	VMXREG_16G_INTSTATUS	0x0810

#define	VMXREG_16H_ES_SEL	0x0c00
#define	VMXREG_16H_CS_SEL	0x0c02
#define	VMXREG_16H_SS_SEL	0x0c04
#define	VMXREG_16H_DS_SEL	0x0c06
#define	VMXREG_16H_FS_SEL	0x0c08
#define	VMXREG_16H_GS_SEL	0x0c0a
#define	VMXREG_16H_TR_SEL	0x0c0c

#define	VMXREG_64C_IOMAP_A	0x2000
#define	VMXREG_64C_IOMAP_B	0x2002
#define	VMXREG_64C_MSRMAP	0x2004
#define	VMXREG_64C_EXIT_MSR_ST	0x2006
#define	VMXREG_64C_EXIT_MSR_LD	0x2008
#define	VMXREG_64C_ENTRY_MSR_LD	0x200a
#define	VMXREG_64C_EXEC_VMCS	0x200c
//
#define	VMXREG_64C_TSC_OFFSET	0x2010
#define	VMXREG_64C_VAPIC_ADDR	0x2012
#define	VMXREG_64C_APIC_ADDR	0x2014
#define	VMXREG_64C_POSTEDINT_DESC	0x2016
#define	VMXREG_64C_VMFUNC_CTL	0x2018
#define	VMXREG_64C_EPTP		0x201a
#define	VMXREG_64C_EOIMAP_0	0x201c
#define	VMXREG_64C_EOIMAP_1	0x201e
#define	VMXREG_64C_EOIMAP_2	0x2020
#define	VMXREG_64C_EOIMAP_3	0x2022
#define	VMXREG_64C_EPTP_LIST	0x2024
#define	VMXREG_64C_VMREADMAP	0x2026
#define	VMXREG_64C_VMWRITEMAP	0x2028
#define	VMXREG_64C_VIRTEXCINFO	0x202a
#define	VMXREG_64C_XSSMAP	0x202c

#define	VMXREG_64E_GPHYS	0x2400

#define	VMXREG_64G_VMCS_LINK	0x2800
#define	VMXREG_64G_IA32_DEBUGCTL	0x2802
#define	VMXREG_64G_IA32_PAT	0x2804
#define	VMXREG_64G_IA32_EFER	0x2806
#define	VMXREG_64G_IA32_PERF_GLOBAL_CTRL	0x2808
#define	VMXREG_64G_PDPTE0	0x280a
#define	VMXREG_64G_PDPTE1	0x280c
#define	VMXREG_64G_PDPTE2	0x280e
#define	VMXREG_64G_PDPTE3	0x2810

#define	VMXREG_64H_IA32_PAT	0x2c00
#define	VMXREG_64H_IA32_EFER	0x2c02
#define	VMXREG_64H_IA32_PERF_GLOBAL_CTRL	0x2c04

#define	VMXREG_32C_PINBASED	0x4000
#define	VMXREG_32C_PRIMARY	0x4002
#define	VMXREG_32C_EXCMAP	0x4004
#define	VMXREG_32C_PFEC_MASK	0x4006
#define	VMXREG_32C_PFEC_MATCH	0x4008
#define	VMXREG_32C_CR3_COUNT	0x400a
#define	VMXREG_32C_EXITCONTROL	0x400c
#define	VMXREG_32C_EXIT_MSR_ST_CNT	0x400e
#define	VMXREG_32C_EXIT_MSR_LD_CNT	0x4010
#define	VMXREG_32C_ENTRYCONTROL	0x4012
#define	VMXREG_32C_ENTRY_MSR_LD_CNT	0x4014
#define	VMXREG_32C_ENTRY_INTINFO	0x4016
#define	VMXREG_32C_ENTRY_EXC_EC	0x4018
#define	VMXREG_32C_INSN_LENGTH	0x401a
#define	VMXREG_32C_TPR_THRESHOLD	0x401c
#define	VMXREG_32C_SECONDARY	0x401e
#define	VMXREG_32C_PLE_GAP	0x4020
#define	VMXREG_32C_PLE_WINDOW	0x4022

#define	VMXREG_32E_INSN_ERROR	0x4400
#define	VMXREG_32E_EXIT_REASON	0x4402
#define	VMXREG_32E_EXIT_INTINFO	0x4404
#define	VMXREG_32E_EXIT_INT_EC	0x4406
#define	VMXREG_32E_IDT_VECINFO	0x4408
#define	VMXREG_32E_IDT_VEC_EC	0x440a
#define	VMXREG_32E_INSN_LENGTH	0x440c
#define	VMXREG_32E_INSN_INFO	0x440e

#define	VMXREG_32G_ES_LIMIT	0x4800
#define	VMXREG_32G_CS_LIMIT	0x4802
#define	VMXREG_32G_SS_LIMIT	0x4804
#define	VMXREG_32G_DS_LIMIT	0x4806
#define	VMXREG_32G_FS_LIMIT	0x4808
#define	VMXREG_32G_GS_LIMIT	0x480a
#define	VMXREG_32G_LDTR_LIMIT	0x480c
#define	VMXREG_32G_TR_LIMIT	0x480e
#define	VMXREG_32G_GDTR_LIMIT	0x4810
#define	VMXREG_32G_IDTR_LIMIT	0x4812
#define	VMXREG_32G_ES_ACCESS	0x4814
#define	VMXREG_32G_CS_ACCESS	0x4816
#define	VMXREG_32G_SS_ACCESS	0x4818
#define	VMXREG_32G_DS_ACCESS	0x481a
#define	VMXREG_32G_FS_ACCESS	0x481c
#define	VMXREG_32G_GS_ACCESS	0x481e
#define	VMXREG_32G_LDTR_ACCESS	0x4820
#define	VMXREG_32G_TR_ACCESS	0x4822
#define	VMXREG_32G_INTSTATE	0x4824
#define	VMXREG_32G_ACTSTATE	0x4826
#define	VMXREG_32G_SMBASE	0x4828
#define	VMXREG_32G_IA32_SYSENTER_CS	0x482a
//
#define	VMXREG_32G_PREEMPT_TIMER	0x482e

#define	VMXREG_32H_IA32_SYSENTER_CS	0x4c00

#define	VMXREG_NWC_CR0_MASK	0x6000
#define	VMXREG_NWC_CR4_MASK	0x6002
#define	VMXREG_NWC_CR0_READ_SHADOW	0x6004
#define	VMXREG_NWC_CR4_READ_SHADOW	0x6006
#define	VMXREG_NWC_CR3_TARGET0	0x6008
#define	VMXREG_NWC_CR3_TARGET1	0x600a
#define	VMXREG_NWC_CR3_TARGET2	0x600c
#define	VMXREG_NWC_CR3_TARGET3	0x600e

#define	VMXREG_NWE_EXITQUAL	0x6400
#define	VMXREG_NWE_IO_RCX	0x6402
#define	VMXREG_NWE_IO_RSI	0x6404
#define	VMXREG_NWE_IO_RDI	0x6406
#define	VMXREG_NWE_IO_RIP	0x6408
#define	VMXREG_NWE_GUEST_LADDR	0x640a

#define	VMXREG_NWG_CR0		0x6800
#define	VMXREG_NWG_CR3		0x6802
#define	VMXREG_NWG_CR4		0x6804
#define	VMXREG_NWG_ES_BASE	0x6806
#define	VMXREG_NWG_CS_BASE	0x6808
#define	VMXREG_NWG_SS_BASE	0x680a
#define	VMXREG_NWG_DS_BASE	0x680c
#define	VMXREG_NWG_FS_BASE	0x680e
#define	VMXREG_NWG_GS_BASE	0x6810
#define	VMXREG_NWG_LDTR_BASE	0x6812
#define	VMXREG_NWG_TR_BASE	0x6814
#define	VMXREG_NWG_GDTR_BASE	0x6816
#define	VMXREG_NWG_IDTR_BASE	0x6818
#define	VMXREG_NWG_DR7		0x681a
#define	VMXREG_NWG_RSP		0x681c
#define	VMXREG_NWG_RIP		0x681e
#define	VMXREG_NWG_RFLAGS	0x6820
#define	VMXREG_NWG_PENDING_DEBUG_EXC	0x6822
#define	VMXREG_NWG_IA32_SYSENTER_ESP	0x6824
#define	VMXREG_NWG_IA32_SYSENTER_EIP	0x6826

#define	VMXREG_NWH_CR0		0x6c00
#define	VMXREG_NWH_CR3		0x6c02
#define	VMXREG_NWH_CR4		0x6c04
#define	VMXREG_NWH_FS_BASE	0x6c06
#define	VMXREG_NWH_GS_BASE	0x6c08
#define	VMXREG_NWH_TR_BASE	0x6c0a
#define	VMXREG_NWH_GDTR_BASE	0x6c0c
#define	VMXREG_NWH_IDTR_BASE	0x6c0e
#define	VMXREG_NWH_IA32_SYSENTER_ESP	0x6c10
#define	VMXREG_NWH_IA32_SYSENTER_EIP	0x6c12
#define	VMXREG_NWH_RSP		0x6c14
#define	VMXREG_NWH_RIP		0x6c16

#endif
