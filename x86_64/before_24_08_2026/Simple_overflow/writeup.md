# Information
Source: crackmes.one
Link: https://crackmes.one/crackme/645d3d4e33c5d43938913079
Platform/ Architecture: Unix/Linux etc - x86_64
Difficulty: 1.5
Tools User: objdump and gdb

# Solution
    1182:       bf 10 00 00 00          mov    $0x10,%edi
    1187:       e8 d4 fe ff ff          call   1060 <malloc@plt>
    118c:       48 89 45 f0             mov    %rax,-0x10(%rbp)
    1190:       bf 08 00 00 00          mov    $0x8,%edi
    1195:       e8 c6 fe ff ff          call   1060 <malloc@plt>
    119a:       48 89 45 f8             mov    %rax,-0x8(%rbp)

- Login function allocated 16 bytes in -0x10(%rbp) that input
- 8 byte stored in -0x8(%rbp) that has value 1
- Can set -0x8(%rbp) equels 1 in order to login with admin
- Input: 16 bytes + 8 bytes (malloc) + 8 bytes value in -0x8(%rbp)
=> Payload: python3 -c "import sys; sys.stdout.buffer.write(b'A' * 24 + 8 * b'0')" 
