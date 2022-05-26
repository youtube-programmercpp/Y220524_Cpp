#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdexcept> //std::runtime_error
#include <sstream>


struct File {
	FILE* fp;

	//�ϊ��R���X�g���N�^
	File(FILE*&& fp) noexcept
		: fp{ fp }
	{
		fp = nullptr;
	}
	//�ړ��R���X�g���N�^
	File(File&& r) noexcept
		: File{std::move(r.fp)}
	{
	}
	//�ړ�������Z�q
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
				<< "�t�@�C���u" << filename << "�v�̃I�[�v���Ɏ��s���܂����B").str());
	}
};




int main()
{
	try {
		auto file = File::OpenForInput(__FILE__);
		//file2.fp �� file.fp �������ɂȂ�

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
