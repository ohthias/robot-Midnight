// Canal do sensor ativo nas portas do expansor de comunicação
void canalSensor(uint8_t canal) {
    Wire.beginTransmission(PCA9548A_ADDR);
    Wire.write(1 << canal);
    Wire.endTransmission();
}

// Conversão de RGB para Matriz(H) Saturação(S) Brilho(B)
void rgbToHSB(int r, int g, int b) {
    float R = float(r) / 255.0;
    float G = float(g) / 255.0;
    float B = float(b) / 255.0;

    float max_val = max(R, max(G, B));
    float min_val = min(R, min(G, B));
    float delta = max_val - min_val;

    brightness = max_val;
    saturation = (max_val == 0) ? 0 : delta / max_val;

    if (delta != 0) {
        if (max_val == R) {
            hue = 60 * fmod((G - B) / delta, 6);
        } else if (max_val == G) {
            hue = 60 * ((B - R) / delta + 2);
        } else {
            hue = 60 * ((R - G) / delta + 4);
        }
    }

    if (hue < 0) {
        hue += 360;
    }
}