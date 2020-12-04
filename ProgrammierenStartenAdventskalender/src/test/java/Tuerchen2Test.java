import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

class Tuerchen2Test {

    @Test
    void testDecimalToBinary() {
        assertEquals(Tuerchen2.decimalToBinary(10), "1010");
        assertEquals(Tuerchen2.decimalToBinary(1), "1");
    }
}