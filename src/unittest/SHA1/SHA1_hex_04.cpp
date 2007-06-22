/*******************************************************************************

   Copyright (C) 2007 M.K.A. <wyrmchild@users.sourceforge.net>

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.

*******************************************************************************/

#include "shared/SHA1.h"

#include <iostream>
#include <memory>

int main()
{
	SHA1 hash;
	
	unsigned char src[] = "abc";
	
	hash.Update(src, strlen(reinterpret_cast<char*>(src)));
	hash.Final();
	
	char hexdigest[41];
	hash.HexDigest(hexdigest);
	hexdigest[40] = '\0';
	
	char res[] = "A9993E364706816ABA3E25717850C26C9CD0D89D";
	
	int rv = memcmp(hexdigest, res, 40);
	if (rv != 0)
		std::cerr << "result  : " << hexdigest << std::endl << "expected: " << res << std::endl;
	
	return (rv == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
