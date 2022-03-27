# Seeeduino XIAO Macro Pad
Three arcade button macro pad running on the Seeeduino XIAO

![56F65AC1-EC17-4B85-9973-35D0480C4EA6](https://user-images.githubusercontent.com/1091484/160261219-ef59ccc7-6921-4b5b-947e-37ae5bf2e083.jpeg)
## Features
Three hotkey buttons with four different hot key mappings. An LED indicates which hot key set is currently in use.
Hold down the right or left buttons to shift through hot key sets.
#### Set One: Virtual Desktop Management (Windows only)
`Virtual Desktop Left`
`Task View`
`Virutal Desktop Right`

#### Set Two: Clipboard
`Copy`
`Cut`
`Paste`

#### Set Three: Undo/Redo
`Undo`
`Redo`
`Cut`

#### Set Four: Keys for games
`Z`
`X`
`C`

## Make your own!

### Parts list
- 1x Seeeduino XIAO [Amazon](https://www.amazon.com/Seeeduino-Smallest-Microcontroller-Interfaces-Compatible/dp/B08745JBRP/ref=sxts_rp_s_a1_0?crid=36ESBJ7XJR582&cv_ct_cx=Seeeduino+XIAO&keywords=Seeeduino+XIAO&pd_rd_i=B08745JBRP&pd_rd_r=6079697b-7c90-4b91-8540-13967a7465d3&pd_rd_w=1zeaF&pd_rd_wg=kJSrK&pf_rd_p=ef09fc8b-f6fe-450c-ac89-05f354bc6e1d&pf_rd_r=8T6GWNAQJPXVC8BZ0YGV&psc=1&qid=1646352611&sprefix=seeeduino+xiao%2Caps%2C131&sr=1-1-5985efba-8948-4f09-9122-d605505c9d1e)
- 3x Arcade Buttons [Amazon](https://www.amazon.com/gp/product/B01LXZSV2N/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1) [Rough Pinout](https://m.media-amazon.com/images/S/aplus-seller-content-images-us-east-1/ATVPDKIKX0DER/A3H7VB6FZ4M9FM/a9c8a56d-7226-4e97-8797-9c16c0321ef7._CR0,0,300,300_PT0_SX300__.jpg)
- 1x WS2812b LED [Amazon](https://www.amazon.com/gp/product/B07BTTY4FL/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1)
- 3x 10k Resistors for pulldown buttons
- 1x 3d Printed Case (STL Files in the construction folder!)

### Breadboard
![MacroXiaoBread](https://user-images.githubusercontent.com/1091484/160261648-18d80124-ad82-424f-b0ea-a0dc8765c7ac.png)

### Electrical Diagram
![MacroXiaoSchematic](https://user-images.githubusercontent.com/1091484/160261650-d3b63b3d-3ad7-466d-b447-303c4331282c.png)

## Libraries 
- [Keyboard.h](https://github.com/arduino-libraries/Keyboard)
- [OneButton](https://github.com/mathertel/OneButton)
- [FastLED](https://github.com/FastLED/FastLED)
