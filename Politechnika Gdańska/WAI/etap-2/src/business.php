<?php
use MongoDB\BSON\ObjectID;

function get_db()
{
    $mongo = new MongoDB\Client(
        "mongodb://localhost:27017/wai",
        [
            'username' => 'wai_web',
            'password' => 'w@i_w3b',
        ]);

    $db = $mongo->wai;

    return $db;
}

function get_pictures()
{
    $db = get_db();
    return $db->pictures->find()->toArray();
}

function get_pictures_by_cat($cat)
{
    $db = get_db();
    $pictures = $db->pictures->find(['cat' => $cat]);
    return $pictures;
}

function get_picture_by_id($id)
{
    $db = get_db();
    $picture = $db->pictures->findOne(['id' => $id]);
    return $picture;
}

function handle_image_upload(){
        //VALIDATION
        if($_FILES['file']['size'] > 1024 * 1024){
            return 'redirect:/upload?error=2';
        }

        //FINAL UPLOAD
        $targetDirectory = "./images/";
        $id = uniqid();
        if($_FILES['file']['type'] === 'image/png'){
            $targetFile = $targetDirectory . $id . '.png';
        }
        else if($_FILES['file']['type'] === 'image/jpeg'){
            $targetFile = $targetDirectory . $id . '.jpg';
        }
        else{
            return 'redirect:/upload?error=1';

        }


        if(move_uploaded_file($_FILES["file"]["tmp_name"], $targetFile)){
            $db = get_db();
            $picture_info = [
                'id' => $id,
                'cat' => $_POST['cat'],
                'tytul' => $_POST['tytul'],
                'autor' => $_POST['autor'],
                'path' => $targetFile,
                'watermark' => $_POST['watermark'],
            ];
            try {
                $db->pictures->insertOne($picture_info);
            } catch (Exception $e) {
                // Handle the error here
                return 'redirect:/upload?error=3';
            }
            miniaturka($targetFile, $picture_info);
            watermark_picture($targetFile, $picture_info);
            return 'redirect:/cats/galeria';
        }
        return 'redirect:/cats/galeria';

}
