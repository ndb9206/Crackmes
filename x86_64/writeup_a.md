---
title: Information

---

# Information
Source: crackmes.one
Link: https://crackmes.one/crackme/645d3d4e33c5d43938913079
Platform/ Architecture: Unix/Linux etc - x86_64
Difficulty: 1.5
Tools User: objdump and gdb

# Static Analysis
- First, program set -0x4(%rbp) = -0x8(%rbp) = 0x2
- -0x8(%rbp) compare with 0x13 -> loop: caculate the value -0x4(%rbp)
- After, input compare with the value in -0x4(%rbp)

# Solution
1. Set value in -0x8(%rbp) equals 0x14
- Use gdb
- Add breakpoint in address 0x55555555516b
![image](https://hackmd.io/_uploads/rJ6iXsgvfx.png)
- Using set {int}($rbp - 0x8) = 20 (=0x14)
- Input value: 2
- Flag: I_LOVE_YOU
3. Find the value in -0x4(%rbp)
- Use gdb
- Add breakpoint in address 0x5555555551ad
- Use x/d $rbp-0x4
![image](https://hackmd.io/_uploads/HkghSjeDGx.png)
- Value in -0x4(%rbp) = 219283456
- Flag: I_LOVE_YOU