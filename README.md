# SmartPAD
Custom Macropad that I can alternate between Wall Mode (where it acts like a smart home device and can change things around the house) and Keyboard Mode (where it acts as an extension of my keyboard and could do certain programmable things).

EasyEDA link: https://oshwlab.com/neev.dharod/project_qsxulqkk

# CAD

Onshape Link: https://cad.onshape.com/documents/78aa9a4f8f3dff9ac8d289c6/w/14a2d0494b635a78e9d4ba0a/e/a2543730fb8388abf7394891?renderMode=0&uiState=6a3596b5da4b181361d0cce9

Includes Full Assembly, Case, including Wall Mount

<img width="571" height="501" alt="Screenshot 2026-06-19 12 21 11 PM" src="https://github.com/user-attachments/assets/a4d934e6-d769-4364-996a-56fb7db555a9" />

<img width="569" height="369" alt="Screenshot 2026-06-19 12 22 53 PM" src="https://github.com/user-attachments/assets/c7c0a1c7-b886-4b77-8d03-ea6212619434" />

# Electronic Schematic

<img src="https://cdn.hackclub.com/019e9141-0046-7146-a050-821bf7a5f80e/Screenshot%202026-06-03%209.57.40%20PM.png" alt="image"/>

# PCB

<img src="https://cdn.hackclub.com/019e959a-5d68-7aef-b7ab-93cf21a985e7/Screenshot%202026-06-04%206.09.48%20PM.png" alt="image"/>

<img src="https://cdn.hackclub.com/019e959a-78ae-7550-9f26-08da6d75c7e8/Screenshot%202026-06-04%206.09.39%20PM.png" alt="image"/>

# Key Features
Includes:
- 6 custom programmable keys
- Rotary encoder knob
- 2.42 Inch OLED display
- XIAO ESP32S3

# Why/How

I created this project because I wanted to have a first hand look on how I can use PCBs. I didn't want to make just a basic macropad, since that would be boring and uninteresting, so I decided to add some extra features. This would also teach me some basics of PCB soldering and other things. 

To create this project, first I will order the parts for this project.
1. Then, I will first use a breadboard (which I have) to test out my components first. I will run some programs to check if it works, etc.
2. If everything works, I will start moving to the PCB. I will solder on the pieces to the PCB.
3. Then, I will run another program check to see if the PCB works.
4. If the PCB works well, I will write a final program which includes the smart features and everything I want to add.
5. I will now add the keybuttons onto the hotswap so I can do some testing.
6. Finally, I will remeasure my components, adjust the CAD if needed, print the CADs and put the final project together.

# Potential Challenges

Some potential challenges I might have are the CAD being slightly off, since I am using AliExpress which is not very exact for their measurements. This can be easily fixable, since I have a digital caliper I can use to make sure my measurements and things are exact. Another challenge I might face is my soldering, since I have never soldered before, but one of my friends who solders alot will help me so this shouldn't be an issue. I will also practice soldering before trying on the PCB.


# BOM
| Recommended part / description                                                    | Qty | Source / buy link                                                 | total (USD) |
|-----------------------------------------------------------------------------------|-----|-------------------------------------------------------------------|-------------|
| Seeed Studio XIAO ESP32S3                                                         | 1   | https://www.seeedstudio.com/XIAO-ESP32S3-p-5627.html              | $13.08      |
| 2.42 inch OLED Display Module 128x64 SSD1309, I2C/IIC interface, white, black PCB | 1   | https://www.aliexpress.com/item/3256811431549511.html             | $12.22      |
| Gateron Milky Yellow Pro V3 MX-style switches                                     | 1   | https://www.aliexpress.com/item/3256812103948628.html             | $4.57       |
| Kailh MX hot-swap sockets CPG151101S11-1                                          | 1   | https://holykeebs.com/products/kailh-mx-hotswap-sockets-10-pack   | $2.12       |
| JCD 10PCS blank 1U XDA keycaps, MX compatible                                     | 1   | https://www.aliexpress.com/item/3256808218107778.html             | $4.15       |
| EC11 rotary encoder with push button, 15mm shaft option                           | 1   | https://www.aliexpress.com/item/3256806273846536.html             | $0.75       |
| 6mm shaft aluminum/alloy knob cap                                                 | 1   | https://www.aliexpress.com/item/3256805576156240.html             | $1.98       |
| JLCPCB custom 2-layer PCB, 110mm x 70mm, 5 pcs                                    | 1   | https://jlcpcb.com/                                               | $8.40       |
| 1x7 2.54mm through-hole pin header                                                | 1   | https://www.aliexpress.com/w/wholesale-1x7-2.54mm-pin-header.html | $15.58      |
| Dupont/jumper wire kit or silicone hookup wire                                    | 1   | https://www.aliexpress.com/w/wholesale-dupont-wire-kit.html       | $2.93       |
| Soldering wire                                                                    | 1   | https://www.aliexpress.com/w/wholesale-m3-screw-assortment.html   | $14.12      |
|                                                                                   |     | Total                                                             | $79.90      |
|                                                                                   |     | Discounts In Total                                                | $58.40      |
