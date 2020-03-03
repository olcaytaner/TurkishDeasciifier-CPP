# Deasciifier

Nlptoolkit’in bu bileşeni, Türkçe karakterler içeren metinleri Türkçe karakterlerden arındırmak veya Türkçe karakterlerden arındırılmısı bir metnin Türkçe karakterlerini geri kazandırmak için kullanılabilir. Bu araç, bir metni Türkçe karakterlerden arındırmak için oldukça basit bir yol takip etmektedir ve her bir Türkçe karakteri karşılık gelen Latince haline dönüştürmektedir. Örneğin, Ç harfleri C’ye çevrilirken, ı harfi i harfine çevrilmektedir.

Bir metne Türkçe karakterleri geri kazandırmak için ise araç iki farklı yöntem içermektedir. Bu yöntemlerin ilki basit geri dönüştürücüdür (simple deasciifier). Bu yöntem, bir kelimenin var olabilecek bütün Türkçe karakter karşılıklarını oluşturmakta ve bu seçeneklerden biçimbirimsel olarak çözümlenebilen bir tanesini rassal olarak seçip sonuç olarak sunmaktadır. Örneğin, cocuk girdisi için, basit geri dönüştürücü cocuk, çocuk, coçuk ve çoçuk seçeneklerini yaratacak ve sadece çocuk biçimbirimsel olarak çözümlenebileceği için çocuk kelimesini çıktı olarak verecektir. Diğer yöntem ise n-karakter geri dönüştürücüdür (ngram deasciifier). Bu yöntemde ise, yine her bir kelime için ilk yöntemdeki gibi bir aday listesi oluşturulur ve ardından her bir kelimenin Türkçe’deki n-karakter olasılıkları hesaplanarak en muhtemel aday çıktı olarak verilir.


------------------
You can also see either [Python](https://github.com/olcaytaner/TurkishDeasciifier-Py) 
or [Java](https://github.com/olcaytaner/TurkishDeasciifier) repository.
