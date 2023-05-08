import allFunction from "./w3.js";

const testcases = {
  sumNumber: [
    ["0"],
    ["5"],
    ["99999"],
    ["1111"],
    ["1000"],
    ["1314"],
    ["5432"],
    ["1029"],
    ["1928283"],
    ["17283746"],
  ],
  sumNumberAns: [0, 5, 45, 4, 1, 9, 14, 12, 33, 38],
  sumVowel: [
    ["sau lay"],
    ["chi co lam"],
    ["chiu kho"],
    ["can cu thi bu sieng lang"],
    [" co lam thi moi co an"],
    [", "],
    ["khong lam ma doi co an"],
    [" thi se khong "],
    [" lam duoc may bai css nay dau"],
    [" =))"],
  ],
  sumVowelAns: [3, 3, 3, 7, 7, 0, 7, 3, 9, 0],
  binaryMax: [
    ["110"],
    ["010"],
    ["11111"],
    ["1101"],
    ["01110"],
    ["0101010"],
    ["1111011101011"],
    ["11001001"],
    ["001011100110"],
    ["0111001111000"],
  ],
  binaryMaxAns: [
    "11",
    "1",
    "11111",
    "11",
    "111",
    "1",
    "1111",
    "11",
    "111",
    "1111",
  ],
  sumNotFour: [
    [[1, 1, 1]],
    [[2, 2, 2]],
    [[1, 2, 3, 4, 5]],
    [[4, 5, 5, 5]],
    [[2]],
    [[3]],
    [[1, 2, 2]],
    [[1, 2, 4]],
    [[3, 5, 6, 7]],
    [[8, 9, 10]],
  ],
  sumNotFourAns: [0, 0, 8, 15, 0, 3, 0, 0, 21, 27],
  uniqueArr: [
    [[1, 1, 1]],
    [[1, 2, 1, 1]],
    [[3, 2, 2, 1]],
    [[3, 1, 1, 1]],
    [[1, 5, 2, 5]],
    [[5, 4, 3, 2]],
    [[7, 4, 5, 4, 4, 4]],
    [[3, 2, 3, 8, 8, 8, 4, 4]],
    [[3, 2, 3, 3, 4, 3, 3, 1]],
    [[1, 5, 4, 3, 4, 5, 2, 1, 4, 3, 2]],
  ],
  uniqueArrAns: [
    [1],
    [1, 2],
    [1, 2, 3],
    [1, 3],
    [1, 2, 5],
    [2, 3, 4, 5],
    [4, 5, 7],
    [2, 3, 4, 8],
    [1, 2, 3, 4],
    [1, 2, 3, 4, 5],
  ],
  equalTwoArr: [
    [
      [1, 2],
      [1, 1],
    ],
    [
      [1, 2, 3],
      [1, 1, 1],
    ],
    [
      [1, 2, 3, 4],
      [1, 1, 1, 4],
    ],
    [
      [1, 2, 3],
      [1, 2, 3],
    ],
    [
      [4, 3, 4, 2],
      [1, 2, 3, 4],
    ],
    [
      [1, 2, 1, 2, 1, 2, 1, 2],
      [1, 1, 1, 1, 1, 2, 1, 1],
    ],
  ],
  equalTwoArrAns: [1, 1, 2, 3, 0, 5],
  mergeArr: [
    [
      [1, 2],
      [1, 1],
    ],
    [
      [1, 2, 3],
      [1, 10, 1],
    ],
    [
      [2, 3, 4, 1],
      [1, 10, 4, 1],
    ],
    [
      [1, 2, 30],
      [1, 20, 3],
    ],
    [
      [4, 3, 40, 2],
      [10, 20, 3, 4],
    ],
    [
      [1, 2, 1, 2, 1, 2, 1, 2],
      [1, 1, 1, 1, 1, 2, 1, 1],
    ],
  ],
  mergeArrAns: [
    [1, 2],
    [1, 2, 3, 10],
    [1, 2, 3, 4, 10],
    [1, 2, 3, 20, 30],
    [2, 3, 4, 10, 20, 40],
    [1, 2],
  ],
};

const checkTestCase = () => {
  console.log(allFunction, "allfunc");
  return Object.keys(allFunction).map((key) => {
    return {
      title: key,
      ans: testcases[key].map((params, idx) => {
        const output = allFunction[key](...params);
        console.log(key, [params], output, testcases[key + "Ans"][idx]);
        if (typeof output !== "object") {
          return {
            output,
            target: testcases[key + "Ans"][idx],
            status: output === testcases[key + "Ans"][idx],
          };
        }
        return {
          output,
          target: testcases[key + "Ans"][idx],
          status: testcases[key + "Ans"][idx].reduce(
            (a, b, idx) => a && b === output[idx],
            true
          ),
        };
      }),
    };
  });
};

document.getElementById("root").innerHTML = checkTestCase()
  .map((item, index) => {
    return `
    <div>
    <div class="ques">Câu ${index + 1}: ${item.title}</div>
    ${item.ans.reduce(
      (a, b, idx) =>
        a +
        `
        <div>
        ${
          b.status
            ? `<div>Testcase ${idx + 1}: <span class="dung">Đúng</span></div>`
            : `<div>Testcase ${idx + 1}: <span class="sai">Sai</span></div>`
        }
        <div>Output: ${b.output}</div>
        <div>Target : ${b.target}</div>
        </br>
        </div>
        `,
      ""
    )}
    <br />
    </div>
    `;
  })
  .join("");
  