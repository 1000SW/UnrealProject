# Unreal Portfolio

포토폴리오 목적으로 제작된 소울 시리즈를 모작한 간단한 데모 게임입니다. 대부분을 C++로 제작했지만 몇몇 기능은 블루프린트로 구현하였습니다.

엔진 : Unreal Engine 5 5.2

IDE : Visual Studio 2022

개발규모 : 1인개발

장르 : 소울라이크

작업기간 : 세달 내외

빌드 파일 구글드라이브 주소 : https://drive.google.com/file/d/1LNwyTIZa6yhML7OnQz_YnVUjFUCm73Wc/view?usp=drive_link

# 데모 동영상 및 기술 설명 영상
<https://www.youtube.com/watch?v=lfnCu4sRWYs&ab_channel=SWChun>

# 기술 설명서
#### 클래스 다이어그램
![이미지 이름](https://github.com/MochiChun/UnrealProject/blob/main/New.drawio%20(1).png?raw=true)


# 구현사항
- 캐릭터 이동과 점프 및 아이템 사용, 공격, 구르기, 록온 시스템, 세이브 로드 시스템 등등
- 캐릭터의 스텟과 같은 능력치 시스템

아이템은 인벤토리 컴포넌트와 상호작용해서 아이템을 관리하게 됩니다. 

주변의 떨어져있는 아이템들을 습득하게 되면, 인벤토리 컴포넌트에서 따로 만들어놓은 FItemStruc 구조체 배열에 아이템 데이터를 정해진 로직에 맞춰서 Add하게 됩니다. 해당 기능은 인벤토리 컴포넌트의 AddItem함수를 통해서 일어나게 됩니다.
인벤토리를 담당하는 위젯은 인벤토리를 열거나 하는 요청이 들어오면 해당 배열에 들어있는 데이터에 맞춰서 내용을 업데이트하게 됩니다. 아래는 인벤토리를 담당하는 위젯이 Update하는 기능을 담은 사진입니다.

![이미지 이름](https://github.com/MochiChun/UnrealProject/blob/main/%EC%9D%B8%EB%B2%A4%ED%86%A0%EB%A6%AC%20%EC%97%85%EB%8D%B0%EC%9D%B4%ED%8A%B8.png)

아이템을 담당하는 기능을 따로 컴포넌트로 떼어놓아서 확장성과 모듈화를 이룰 수 있었습니다.

# 향후 개선 방향
- Behavior Tree를 사용해서 몬스터의 AI를 더 고도화 시켜야 됨. 현재 에디터 내의 버그로 인해서 자꾸 크러쉬가 나서 이 부분은 진행을 못함.
- 게임적 요소 추가 및 더 많은 맵과 몬스터 구현
- 최적화 및 기능 보완
