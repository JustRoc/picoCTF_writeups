
# ReadMyCert

> **Tag:** Medium, Cryptography, picoCTF2023  
> **Author:** SUNDAY JACOB NWANYIM

## Description


> How about we take you on an adventure on exploring certificate signing
> requests Take a look at this CSR file [here](https://artifacts.picoctf.net/c/422/readmycert.csr).

From the description and challenge name, it’s clear that the challenge wants me to read a `CSR (Certificate Signing Request)`.
So, I downloaded the file and checked its details.

    [Linux@Linux ~]$ /Downloads$ file readmycert.csr 
    readmycert.csr: PEM certificate request
    
    [Linux@Linux ~]$ /Downloads$ cat readmycert.csr 
    -----BEGIN CERTIFICATE REQUEST-----
    MIICpzCCAY8CAQAwPDEmMCQGA1UEAwwdcGljb0NURntyZWFkX215Y2VydF8zNzNi
    NGFiMH0xEjAQBgNVBCkMCWN0ZlBsYXllcjCCASIwDQYJKoZIhvcNAQEBBQADggEP
    ADCCAQoCggEBAKr+AToJg/TVTvfd9XzYR0gC5TOXa2+T24gjE8n7SHqynuo0Zlfy
    oCqZHkxLha4QZszow4M+klP9fe1hy90LAU2enQGELrF3OF5SbNIVnPq97qrSHNI7
    D9faAdsBqvezCto1MuMrRD35gwhQPga3WobkMdbJdDwuBpem/Tl3ko3Y9sxq2nAF
    cmMNPj40GLtCfW55O8Awn2uN5gGZe+Nw2ArU9AYFidPtFZjBovHv7BVJz5XlhRhu
    oiBALZES9kgfOyiwZrcJYZCJh9cJz3d+n2roMyAYMM/VZIjl0aZqSdOPeGYzs3GP
    p/jFku8KNBn+mjyyw0H1vRnrK1hkNKXrXOcCAwEAAaAmMCQGCSqGSIb3DQEJDjEX
    MBUwEwYDVR0lBAwwCgYIKwYBBQUHAwIwDQYJKoZIhvcNAQELBQADggEBAG0c6ed5
    a5zHU5IeI1KBvhGa+zGlrbm4lGQnGoI8wwlr6VN6v07/BGpwWfhjJatAOQ3txT5O
    xDrM5A8caxpgGUXmat+C/9XCSQgRA+JckSk3rd6Wz7rYRuKsnycHzVIwyvIgSdjM
    5/RKRdYHyFqYHPo9Tf1fThbV0tyQ+kr0tmsO6ZuaKgyDSxtky4U51XzSByKygHOT
    Oi+VkzWvn74aOgbelBFMz+3vxaRHW85pe93jN6Gvc+HwYzUFja/SZXaN95sNRhcq
    20SbOmg4r2pHUg0Lfs/0EHqDSg6JtKItqZmQUNhUQ7jmL6PtUpQQlkwlfMmEijRn
    vlIEqBAkSbo63XQ=
    -----END CERTIFICATE REQUEST-----

It looks like base64 encoded text. Ehh… what if I just decode it? lol

    [Linux@Linux ~]$ /Downloads$ openssl base64 -d -in readmycert.csr 
    0��0��0<1&0$U
                 picoCTF{read_mycert_3#######}10U)
    �0�     *�H��                                 	ctfPlayer0�"0
    ���:	���N���|�GH�3�ko�ۈ#��Hz���4fW�*�LK��f��Ã>�S�}�a��
                                                             M���.�w8^Rl�������;������
    >>4�B}ny;�0�k���{�p����9w�����j�prc
    �����������Iϕ�n� @-��H;(�f�	a����	�w~�j�3 0��d��ѦjIӏxf3�q���Œ�
    4��<��A�100U%4��\��&0$	*�H��
                 0
    +0      *�H��
    ��>N�:��k`E�j߂����\�)7�ޖϺ�F⬟'�R0�� I����JE��Z��=M�_N��ܐ�J��k雚*
    F*�D�:h8�jGR                                                   �K˅9�|�"��s�:/��5���:ޔL���ŤG[�i{��7��s��c5���ev���
    ~��z�J���-���P�TC��/��R��L%|Ʉ�4g�R�$I�:�t

Oh hey, it works. But it's not what this challenge is meant to be, I guess.


Let's do it in the proper way :

    [Linux@Linux ~]$ /Downloads$ openssl req -in readmycert.csr -text
    Certificate Request:
        Data:
            Version: 1 (0x0)
            Subject: CN=picoCTF{read_mycert_3#######}, name=ctfPlayer
            Subject Public Key Info:
                Public Key Algorithm: rsaEncryption
                    Public-Key: (2048 bit)
                    Modulus:
                        00:aa:fe:01:3a:09:83:f4:d5:4e:f7:dd:f5:7c:d8:
                        47:48:02:e5:33:97:6b:6f:93:db:88:23:13:c9:fb:
                        48:7a:b2:9e:ea:34:66:57:f2:a0:2a:99:1e:4c:4b:
                        85:ae:10:66:cc:e8:c3:83:3e:92:53:fd:7d:ed:61:
                        cb:dd:0b:01:4d:9e:9d:01:84:2e:b1:77:38:5e:52:
                        6c:d2:15:9c:fa:bd:ee:aa:d2:1c:d2:3b:0f:d7:da:
                        01:db:01:aa:f7:b3:0a:da:35:32:e3:2b:44:3d:f9:
                        83:08:50:3e:06:b7:5a:86:e4:31:d6:c9:74:3c:2e:
                        06:97:a6:fd:39:77:92:8d:d8:f6:cc:6a:da:70:05:
                        72:63:0d:3e:3e:34:18:bb:42:7d:6e:79:3b:c0:30:
                        9f:6b:8d:e6:01:99:7b:e3:70:d8:0a:d4:f4:06:05:
                        89:d3:ed:15:98:c1:a2:f1:ef:ec:15:49:cf:95:e5:
                        85:18:6e:a2:20:40:2d:91:12:f6:48:1f:3b:28:b0:
                        66:b7:09:61:90:89:87:d7:09:cf:77:7e:9f:6a:e8:
                        33:20:18:30:cf:d5:64:88:e5:d1:a6:6a:49:d3:8f:
                        78:66:33:b3:71:8f:a7:f8:c5:92:ef:0a:34:19:fe:
                        9a:3c:b2:c3:41:f5:bd:19:eb:2b:58:64:34:a5:eb:
                        5c:e7
                    Exponent: 65537 (0x10001)
            Attributes:
                Requested Extensions:
                    X509v3 Extended Key Usage: 
                        TLS Web Client Authentication
        Signature Algorithm: sha256WithRSAEncryption
        Signature Value:
            6d:1c:e9:e7:79:6b:9c:c7:53:92:1e:23:52:81:be:11:9a:fb:
            31:a5:ad:b9:b8:94:64:27:1a:82:3c:c3:09:6b:e9:53:7a:bf:
            4e:ff:04:6a:70:59:f8:63:25:ab:40:39:0d:ed:c5:3e:4e:c4:
            3a:cc:e4:0f:1c:6b:1a:60:19:45:e6:6a:df:82:ff:d5:c2:49:
            08:11:03:e2:5c:91:29:37:ad:de:96:cf:ba:d8:46:e2:ac:9f:
            27:07:cd:52:30:ca:f2:20:49:d8:cc:e7:f4:4a:45:d6:07:c8:
            5a:98:1c:fa:3d:4d:fd:5f:4e:16:d5:d2:dc:90:fa:4a:f4:b6:
            6b:0e:e9:9b:9a:2a:0c:83:4b:1b:64:cb:85:39:d5:7c:d2:07:
            22:b2:80:73:93:3a:2f:95:93:35:af:9f:be:1a:3a:06:de:94:
            11:4c:cf:ed:ef:c5:a4:47:5b:ce:69:7b:dd:e3:37:a1:af:73:
            e1:f0:63:35:05:8d:af:d2:65:76:8d:f7:9b:0d:46:17:2a:db:
            44:9b:3a:68:38:af:6a:47:52:0d:0b:7e:cf:f4:10:7a:83:4a:
            0e:89:b4:a2:2d:a9:99:90:50:d8:54:43:b8:e6:2f:a3:ed:52:
            94:10:96:4c:25:7c:c9:84:8a:34:67:be:52:04:a8:10:24:49:
            ba:3a:dd:74
    -----BEGIN CERTIFICATE REQUEST-----
    MIICpzCCAY8CAQAwPDEmMCQGA1UEAwwdcGljb0NURntyZWFkX215Y2VydF8zNzNi
    NGFiMH0xEjAQBgNVBCkMCWN0ZlBsYXllcjCCASIwDQYJKoZIhvcNAQEBBQADggEP
    ADCCAQoCggEBAKr+AToJg/TVTvfd9XzYR0gC5TOXa2+T24gjE8n7SHqynuo0Zlfy
    oCqZHkxLha4QZszow4M+klP9fe1hy90LAU2enQGELrF3OF5SbNIVnPq97qrSHNI7
    D9faAdsBqvezCto1MuMrRD35gwhQPga3WobkMdbJdDwuBpem/Tl3ko3Y9sxq2nAF
    cmMNPj40GLtCfW55O8Awn2uN5gGZe+Nw2ArU9AYFidPtFZjBovHv7BVJz5XlhRhu
    oiBALZES9kgfOyiwZrcJYZCJh9cJz3d+n2roMyAYMM/VZIjl0aZqSdOPeGYzs3GP
    p/jFku8KNBn+mjyyw0H1vRnrK1hkNKXrXOcCAwEAAaAmMCQGCSqGSIb3DQEJDjEX
    MBUwEwYDVR0lBAwwCgYIKwYBBQUHAwIwDQYJKoZIhvcNAQELBQADggEBAG0c6ed5
    a5zHU5IeI1KBvhGa+zGlrbm4lGQnGoI8wwlr6VN6v07/BGpwWfhjJatAOQ3txT5O
    xDrM5A8caxpgGUXmat+C/9XCSQgRA+JckSk3rd6Wz7rYRuKsnycHzVIwyvIgSdjM
    5/RKRdYHyFqYHPo9Tf1fThbV0tyQ+kr0tmsO6ZuaKgyDSxtky4U51XzSByKygHOT
    Oi+VkzWvn74aOgbelBFMz+3vxaRHW85pe93jN6Gvc+HwYzUFja/SZXaN95sNRhcq
    20SbOmg4r2pHUg0Lfs/0EHqDSg6JtKItqZmQUNhUQ7jmL6PtUpQQlkwlfMmEijRn
    vlIEqBAkSbo63XQ=
    -----END CERTIFICATE REQUEST-----

By using the well-known tool `openssl`, the arguments in the command I use are:

-   `req`: A command used to manage Certificate Signing Requests (CSRs).
-   `-in`: Specifies the input file.
-   `-text`: Outputs the content in a human-readable format.
	
### Answer
`picoCTF{read_mycert_3#######}`

