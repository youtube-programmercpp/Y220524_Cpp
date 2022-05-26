#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdexcept> //std::runtime_error
#include <sstream>


struct File {
	FILE* fp;

	//変換コンストラクタ
	File(FILE*&& fp) noexcept
		: fp{ fp }
	{
		fp = nullptr;
	}
	//移動コンストラクタ
	File(File&& r) noexcept
		: File{std::move(r.fp)}
	{
	}
	//移動代入演算子
	File& operator=(File&& r) noexcept
	{
		std::swap(fp, r.fp);
		return *this;
	}

	~File()
	{
		if (fp)
			(void)fclose(fp);
	}
	File() noexcept
		: File({})
	{
	}
	explicit operator bool() const noexcept
	{
		return fp;
	}
	int read_char() const noexcept
	{
		return fgetc(fp);
	}

	static File OpenForInput(const char* filename)
	{
		if (auto fp = fopen(filename, "r"))
			return { std::move(fp) };
		else
			throw std::runtime_error((std::ostringstream()
				<< "ファイル「" << filename << "」のオープンに失敗しました。").str());
	}
};




int main()
{
	try {
		auto file = File::OpenForInput(__FILE__);
		//file2.fp と file.fp が同じになる

		for (;;) {
			const int ch = file.read_char();
			if (ch == EOF)
				break;
			else
				putchar(ch);
		}
	}
	catch (const std::exception& e) {
		fprintf(stderr, "%s\n", e.what());
	}
}
