# Ascii-Art-from-Text
This is a console application to convert text to ASCII ART.

## Features:
- You have the option of either loading a custom font or using the default font. There are three fonts provided with the application: Grafitti (default), Graceful, and Banner. The ASCII Art fonts are provided in .txt format. You can use your own custom font that you created/downloaded. Please note that this is NOT a regular font in .ttf/.otf format (or any other windows font formats). It's a text file created to be compatible with this software. Please check the ASCII font format part.
- After you enter a text to be converted, you can view the result in the console or start over from the beginning. After you're satisfied with the result, you can output the result to a file.

## ASCII Art font file format:
- 1st line: The height of a single "ASCII Art" letter/digit: an integer representing the number of lines a single "ASCII Art character takes.
- 2nd line: The width of a single "ASCII Art" letter/digit: an integer representing the number of characters a single "ASCII Art character takes.
- The following lines contains the character representations of the 26 letters of the english alphabet followed by the 10 digits (0,1,..,8,9).
Please check the example fonts provided to better understand the format if you're trying to create your own font.
