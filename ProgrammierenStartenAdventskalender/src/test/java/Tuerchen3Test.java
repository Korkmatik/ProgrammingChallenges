import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class Tuerchen3Test {

	@Test
	void test() {
		assertEquals(10, Tuerchen3.convertBinaryToInt("1010"));
		assertEquals(5, Tuerchen3.convertBinaryToInt("101"));
		assertEquals(0, Tuerchen3.convertBinaryToInt("0"));
		assertEquals(1, Tuerchen3.convertBinaryToInt("1"));
		assertEquals(54, Tuerchen3.convertBinaryToInt("110110"));
	}

}
