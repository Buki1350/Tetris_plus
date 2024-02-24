#include "Tetrominos.h"

Tetrominos::Tetrominos()
{
}

Tetrominos::~Tetrominos()
{
}

int* Tetrominos::getShape(int pieceIndex, int rotationNumber)
{
	switch (pieceIndex)
	{
	case 1:
		switch (rotationNumber)
		{
		case 1:
			return IshapeR90;
			break;
		case 2:
			return IshapeR0;
			break;
		case 3:
			return IshapeR90;
			break;
		default:
			return IshapeR0;
			break;
		}
		break;
	case 2:
		switch (rotationNumber)
		{
		case 1:
			return JshapeR90;
			break;
		case 2:
			return JshapeR180;
			break;
		case 3:
			return JshapeR270;
			break;
		default:
			return JshapeR0;
			break;
		}
		break;
	case 3:
		switch (rotationNumber)
		{
		case 1:
			return LshapeR90;
			break;
		case 2:
			return LshapeR180;
			break;
		case 3:
			return LshapeR270;
			break;
		default:
			return LshapeR0;
			break;
		}
		break;
	case 4:
		switch (rotationNumber)
		{
		case 1:
			return ZshapeR90;
			break;
		case 2:
			return ZshapeR0;
			break;
		case 3:
			return ZshapeR90;
			break;
		default:
			return ZshapeR0;
			break;
		}
		break;
	case 5:
		switch (rotationNumber)
		{
		case 1:
			return SshapeR90;
			break;
		case 2:
			return SshapeR0;
			break;
		case 3:
			return SshapeR90;
			break;
		default:
			return SshapeR0;
			break;
		}
		break;
	case 6:
		switch (rotationNumber)
		{
		case 1:
			return TshapeR90;
			break;
		case 2:
			return TshapeR180;
			break;
		case 3:
			return TshapeR270;
			break;
		default:
			return TshapeR0;
			break;
		}
		break;
	case 7:
		return OshapeR0;
		break;
	default:
		return nullptr;
	}

}
