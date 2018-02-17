type timeUnit = | Second | Minute | Hour | Day | Month | Year;
type partialMethod = | Floor | Ceil | Round;

let closestIndexTo: (array(Js.Date.t), Js.Date.t) => int;
let closestTo: (array(Js.Date.t), Js.Date.t) => Js.Date.t;

let compareAsc: (Js.Date.t, Js.Date.t) => int;
let compareDesc: (Js.Date.t, Js.Date.t) => int;

let distanceInWords: (~includeSeconds: bool=?, ~addSuffix: bool=?, Js.Date.t, Js.Date.t) => string;
let distanceInWordsStrict: (~addSuffix: bool=?, ~unit: timeUnit=?, ~partialMethod: partialMethod=?, Js.Date.t, Js.Date.t) => string;
let distanceInWordsToNow: (~includeSeconds: bool=?, ~addSuffix: bool=?, Js.Date.t) => string;
let format: (string, Js.Date.t) => string;
/* Flipped parameter order: laterDate |> isAfter(earlierDate) -> true */
let isAfter: (Js.Date.t, Js.Date.t) => bool;
/* Flipped parameter order */
let isBefore: (Js.Date.t, Js.Date.t) => bool;
let isEqual: (Js.Date.t, Js.Date.t) => bool;
let isFuture: Js.Date.t => bool;
let isPast: Js.Date.t => bool;
let isValid: Js.Date.t => bool;
let max: array(Js.Date.t) => Js.Date.t;
let min: array(Js.Date.t) => Js.Date.t;
let parseString: (~additionalDigits: int=?, string) => Js.Date.t;
let parseFloat: (~additionalDigits: int=?, float) => Js.Date.t;

let areRangesOverlapping: (Js.Date.t, Js.Date.t, Js.Date.t, Js.Date.t) => bool;
let getOverlappingDaysInRanges: (Js.Date.t, Js.Date.t, Js.Date.t, Js.Date.t) => float;
/* Parameter order changed to (startDate, endDate, date) => bool */
let isWithinRange: (Js.Date.t, Js.Date.t, Js.Date.t) => bool;

let getTime: Js.Date.t => float;

let addMilliseconds: (float, Js.Date.t) => Js.Date.t;
let differenceInMilliseconds: (Js.Date.t, Js.Date.t) => float;
let getMilliseconds: Js.Date.t => float;
let setMilliseconds: (float, Js.Date.t) => Js.Date.t;
let subMilliseconds: (float, Js.Date.t) => Js.Date.t;

let addSeconds: (float, Js.Date.t) => Js.Date.t;
let differenceInSeconds: (Js.Date.t, Js.Date.t) => float;
let endOfSecond: Js.Date.t => Js.Date.t;
let getSeconds: Js.Date.t => float;
let isSameSecond: (Js.Date.t, Js.Date.t) => bool;
let isThisSecond: Js.Date.t => bool;
let setSeconds: (float, Js.Date.t) => Js.Date.t;
let startOfSecond: Js.Date.t => Js.Date.t;
let subSeconds: (float, Js.Date.t) => Js.Date.t;

let addMinutes: (float, Js.Date.t) => Js.Date.t;
let differenceInMinutes: (Js.Date.t, Js.Date.t) => float;
let endOfMinute: Js.Date.t => Js.Date.t;
let getMinutes: Js.Date.t => float;
let isSameMinute: (Js.Date.t, Js.Date.t) => bool;
let isThisMinute: Js.Date.t => bool;
let setMinutes: (float, Js.Date.t) => Js.Date.t;
let startOfMinute: Js.Date.t => Js.Date.t;
let subMinutes: (float, Js.Date.t) => Js.Date.t;

let addHours: (float, Js.Date.t) => Js.Date.t;
let differenceInHours: (Js.Date.t, Js.Date.t) => float;
let endOfHour: Js.Date.t => Js.Date.t;
let getHours: Js.Date.t => float;
let isSameHour: (Js.Date.t, Js.Date.t) => bool;
let isThisHour: Js.Date.t => bool;
let setHours: (float, Js.Date.t) => Js.Date.t;
let startOfHour: Js.Date.t => Js.Date.t;
let subHours: (float, Js.Date.t) => Js.Date.t;

let addDays: (float, Js.Date.t) => Js.Date.t;
let differenceInCalendarDays: (Js.Date.t, Js.Date.t) => float;
let differenceInDays: (Js.Date.t, Js.Date.t) => float;
let eachDay: (Js.Date.t, Js.Date.t) => array(Js.Date.t);
let endOfDay: Js.Date.t => Js.Date.t;
let endOfToday: unit => Js.Date.t;
let endOfTomorrow: unit => Js.Date.t;
let endOfYesterday: unit => Js.Date.t;
let getDate: Js.Date.t => float;
let getDayOfYear: Js.Date.t => float;
let isSameDay: (Js.Date.t, Js.Date.t) => bool;
let isToday: Js.Date.t => bool;
let isYesterday: Js.Date.t => bool;
let isTomorrow: Js.Date.t => bool;
let setDate: (float, Js.Date.t) => Js.Date.t;
let setDayOfYear: (float, Js.Date.t) => Js.Date.t;
let startOfDay: Js.Date.t => Js.Date.t;
let startOfToday: unit => Js.Date.t;
let startOfTomorrow: unit => Js.Date.t;
let startOfYesterday: unit => Js.Date.t;
let subDays: (float, Js.Date.t) => Js.Date.t;

let getDay: Js.Date.t => float;
let getISODay: Js.Date.t => float;
let isFriday: Js.Date.t => bool;
let isMonday: Js.Date.t => bool;
let isSaturday: Js.Date.t => bool;
let isSunday: Js.Date.t => bool;
let isThursday: Js.Date.t => bool;
let isTuesday: Js.Date.t => bool;
let isWednesday: Js.Date.t => bool;
let isWeekend: Js.Date.t => bool;
let setDay: (float, Js.Date.t) => Js.Date.t;
let setISODay: (float, Js.Date.t) => Js.Date.t;

let addWeeks: (float, Js.Date.t) => Js.Date.t;
let differenceInCalendarWeeks: (Js.Date.t, Js.Date.t) => float;
let differenceInWeeks: (Js.Date.t, Js.Date.t) => float;
let endOfWeek: Js.Date.t => Js.Date.t;
let isSameWeek: (Js.Date.t, Js.Date.t) => bool;
let isThisWeek: Js.Date.t => bool;
let lastDayOfWeek: Js.Date.t => Js.Date.t;
let startOfWeek: Js.Date.t => Js.Date.t;
let subWeeks: (float, Js.Date.t) => Js.Date.t;

let differenceInCalendarISOWeeks: (Js.Date.t, Js.Date.t) => float;
let endOfISOWeek: Js.Date.t => Js.Date.t;
let getISOWeek: Js.Date.t => float;
let isSameISOWeek: (Js.Date.t, Js.Date.t) => bool;
let isThisISOWeek: Js.Date.t => bool;
let lastDayOfISOWeek: Js.Date.t => Js.Date.t;
let setISOWeek: (float, Js.Date.t) => Js.Date.t;
let startOfISOWeek: Js.Date.t => Js.Date.t;

let addMonths: (float, Js.Date.t) => Js.Date.t;
let differenceInCalendarMonths: (Js.Date.t, Js.Date.t) => float;
let differenceInMonths: (Js.Date.t, Js.Date.t) => float;
let endOfMonth: Js.Date.t => Js.Date.t;
let getDaysInMonth: Js.Date.t => float;
let getMonth: Js.Date.t => float;
let isFirstDayOfMonth: Js.Date.t => bool;
let isLastDayOfMonth: Js.Date.t => bool;
let isSameMonth: (Js.Date.t, Js.Date.t) => bool;
let isThisMonth: Js.Date.t => bool;
let lastDayOfMonth: Js.Date.t => Js.Date.t;
let setMonth: (float, Js.Date.t) => Js.Date.t;
let startOfMonth: Js.Date.t => Js.Date.t;
let subMonths: (float, Js.Date.t) => Js.Date.t;

let addQuarters: (float, Js.Date.t) => Js.Date.t;
let differenceInCalendarQuarters: (Js.Date.t, Js.Date.t) => float;
let differenceInQuarters: (Js.Date.t, Js.Date.t) => float;
let startOfQuarter: Js.Date.t => Js.Date.t;
let endOfQuarter: Js.Date.t => Js.Date.t;
let getQuarter: Js.Date.t => float;
let isSameQuarter: (Js.Date.t, Js.Date.t) => bool;
let isThisQuarter: Js.Date.t => bool;
let lastDayOfQuarter: Js.Date.t => Js.Date.t;
let setQuarter: (float, Js.Date.t) => Js.Date.t;
let subQuarters: (float, Js.Date.t) => Js.Date.t;

let addYears: (float, Js.Date.t) => Js.Date.t;
let differenceInCalendarYears: (Js.Date.t, Js.Date.t) => float;
let differenceInYears: (Js.Date.t, Js.Date.t) => float;
let endOfYear: Js.Date.t => Js.Date.t;
let getDaysInYear: Js.Date.t => float;
let getYear: Js.Date.t => float;
let isLeapYear: Js.Date.t => bool;
let isSameYear: (Js.Date.t, Js.Date.t) => bool;
let isThisYear: Js.Date.t => bool;
let lastDayOfYear: Js.Date.t => Js.Date.t;
let setYear: (float, Js.Date.t) => Js.Date.t;
let startOfYear: Js.Date.t => Js.Date.t;
let subYears: (float, Js.Date.t) => Js.Date.t;

let addISOYears: (float, Js.Date.t) => Js.Date.t;
let differenceInCalendarISOYears: (Js.Date.t, Js.Date.t) => float;
let differenceInISOYears: (Js.Date.t, Js.Date.t) => float;
let endOfISOYear: Js.Date.t => Js.Date.t;
let getISOWeeksInYear: Js.Date.t => float;
let getISOYear: Js.Date.t => float;
let isSameISOYear: (Js.Date.t, Js.Date.t) => bool;
let isThisISOYear: Js.Date.t => bool;
let lastDayOfISOYear: Js.Date.t => Js.Date.t;
let setISOYear: (float, Js.Date.t) => Js.Date.t;
let startOfISOYear: Js.Date.t => Js.Date.t;
let subISOYears: (float, Js.Date.t) => Js.Date.t;
