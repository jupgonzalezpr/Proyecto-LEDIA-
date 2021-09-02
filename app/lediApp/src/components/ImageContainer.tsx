import { IonAvatar} from "@ionic/react"
import './ImageContainer.css';

const ImageContainer: React.FC = () =>{
    return (
        <IonAvatar className = 'room'>
            <img  src = "assets/images/masterbedroom.jpg" alt= "Master room image"/>
        </IonAvatar>    
    )
}

export default ImageContainer;